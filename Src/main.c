#include "STM32F407.h"

typedef enum {
	GPIO_CONFIG_OUTPUT_PP = 0,
	GPIO_CONFIG_OUTPUT_PP_PU,
	GPIO_CONFIG_OUTPUT_PP_PD,
	GPIO_CONFIG_OUTPUT_OD,
	GPIO_CONFIG_OUTPUT_OD_PU,
	GPIO_CONFIG_OUTPUT_OD_PD,
	GPIO_CONFIG_AF_PP,
	GPIO_CONFIG_AF_PP_PU,
	GPIO_CONFIG_AF_PP_PD,
	GPIO_CONFIG_AF_OD,
	GPIO_CONFIG_AF_OD_PU,
	GPIO_CONFIG_AF_OD_PD,
	GPIO_CONFIG_INPUT_FLOATING,
	GPIO_CONFIG_INPUT_PU,
	GPIO_CONFIG_INPUT_PD,
	GPIO_CONFIG_ANALOG,
} GPIO_CONFIG;

typedef enum {
	GPIO_SPEED_LOW_SPEED = 0,
	GPIO_SPEED_MEDIUM_SPEED,
	GPIO_SPEED_HIGH_SPEED,
	GPIO_SPEED_VERY_HIGH_SPEED,
} GPIO_SPEED;

typedef enum {
	GPIO_MODE_REGISTER_INPUT = 0,
	GPIO_MODE_REGISTER_OUTPUT,
	GPIO_MODE_REGISTER_ALTERNATE_FUNCTION,
	GPIO_MODE_REGISTER_ANALOG,
} GPIO_MODE;

typedef enum {
	GPIO_PIN_0 = 0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15,
} GPIO_PIN;

typedef enum {
	GPIO_OUTPUT_TYPE_PUSH_PULL = 0,
	GPIO_OUTPUT_TYPE_OPEN_DRAIN,
} GPIO_OUTPUT_TYPE;

typedef enum {
	GPIO_OUTPUT_TYPE_PUSH_PULL = 0,
	GPIO_OUTPUT_TYPE_OPEN_DRAIN,
} GPIO_PUPD;

#define SET_GPIO_MODE(port, pin, mode)  \
do { 									\
	vuint32_t tmp; 						\
	tmp = port->MODER.R; 				\
	tmp &= ~(0x03 << (pin * 2U)); 		\
	tmp |= (mode << (pin * 2U)); 		\
	port->MODER.R = tmp; 				\
} while(0);

#define SET_GPIO_SPEED(port, pin, speed)  \
do { 									\
	vuint32_t tmp; 						\
	tmp = port->OSPEEDR.R; 				\
	tmp &= ~(0x03 << (pin * 2U)); 		\
	tmp |= (speed << (pin * 2U)); 		\
	port->OSPEEDR.R = tmp; 				\
} while(0);

#define SET_GPIO_OUTPUT_TYPE(port, pin, otype)  \
do { 									\
	vuint32_t tmp; 						\
	tmp = port->OTYPER.R; 				\
	tmp &= ~(0x01 << pin); 				\
	tmp |= (otype << pin);		 		\
	port->OTYPER.R = tmp; 				\
} while(0);

void GPIODriver_Init(volatile struct GPIO_tag *port, GPIO_PIN pin, GPIO_CONFIG config, GPIO_SPEED speed);

void GPIODriver_Init(volatile struct GPIO_tag *port, GPIO_PIN pin, GPIO_CONFIG config, GPIO_SPEED speed)
{
	switch (config) {
		case GPIO_CONFIG_OUTPUT_PP:
			SET_GPIO_MODE(port, pin, GPIO_MODE_REGISTER_OUTPUT);
			SET_GPIO_OUTPUT_TYPE(port, pin, GPIO_OUTPUT_TYPE_PUSH_PULL);
			SET_GPIO_SPEED(port, pin, speed);
			SET_GPIO_PUPD(port, pin, pupd);
			break;
		default:
			// Not reachable
			break;
	}
}

int main(void)
{
	RCC->RCC_AHB1ENR.B.GPIOCEN = 1;

	while(1)
	{
		GPIODriver_Init(GPIOC, GPIO_PIN_5, GPIO_CONFIG_OUTPUT_PP, GPIO_SPEED_HIGH_SPEED);
		GPIODriver_Init(GPIOC, GPIO_PIN_5, GPIO_CONFIG_OUTPUT_PP, GPIO_SPEED_LOW_SPEED);
	}
}

//void GPIODriver_Init(GPIO_Port *port, GPIO_InitStruct *init_struct)
//{
//  uint32_t position;
//  uint32_t ioposition = 0x00U;
//  uint32_t iocurrent = 0x00U;
//  uint32_t temp = 0x00U;
//
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Init->Pin));
//  assert_param(IS_GPIO_MODE(GPIO_Init->Mode));
//  assert_param(IS_GPIO_PULL(GPIO_Init->Pull));
//
//  /* Configure the port pins */
//  for(position = 0U; position < GPIO_NUMBER; position++)
//  {
//    /* Get the IO position */
//    ioposition = 0x01U << position;
//    /* Get the current IO position */
//    iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;
//
//    if(iocurrent == ioposition)
//    {
//      /*--------------------- GPIO Mode Configuration ------------------------*/
//      /* In case of Output or Alternate function mode selection */
//      if((GPIO_Init->Mode == GPIO_MODE_OUTPUT_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_PP) ||
//         (GPIO_Init->Mode == GPIO_MODE_OUTPUT_OD) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
//      {
//        /* Check the Speed parameter */
//        assert_param(IS_GPIO_SPEED(GPIO_Init->Speed));
//        /* Configure the IO Speed */
//        temp = GPIOx->OSPEEDR;
//        temp &= ~(GPIO_OSPEEDER_OSPEEDR0 << (position * 2U));
//        temp |= (GPIO_Init->Speed << (position * 2U));
//        GPIOx->OSPEEDR = temp;
//
//        /* Configure the IO Output Type */
//        temp = GPIOx->OTYPER;
//        temp &= ~(GPIO_OTYPER_OT_0 << position) ;
//        temp |= (((GPIO_Init->Mode & GPIO_OUTPUT_TYPE) >> 4U) << position);
//        GPIOx->OTYPER = temp;
//       }
//
//      /* Activate the Pull-up or Pull down resistor for the current IO */
//      temp = GPIOx->PUPDR;
//      temp &= ~(GPIO_PUPDR_PUPDR0 << (position * 2U));
//      temp |= ((GPIO_Init->Pull) << (position * 2U));
//      GPIOx->PUPDR = temp;
//
//      /* In case of Alternate function mode selection */
//      if((GPIO_Init->Mode == GPIO_MODE_AF_PP) || (GPIO_Init->Mode == GPIO_MODE_AF_OD))
//      {
//        /* Check the Alternate function parameter */
//        assert_param(IS_GPIO_AF(GPIO_Init->Alternate));
//        /* Configure Alternate function mapped with the current IO */
//        temp = GPIOx->AFR[position >> 3U];
//        temp &= ~(0xFU << ((uint32_t)(position & 0x07U) * 4U)) ;
//        temp |= ((uint32_t)(GPIO_Init->Alternate) << (((uint32_t)position & 0x07U) * 4U));
//        GPIOx->AFR[position >> 3U] = temp;
//      }
//
//      /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
//      temp = GPIOx->MODER;
//      temp &= ~(GPIO_MODER_MODER0 << (position * 2U));
//      temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2U));
//      GPIOx->MODER = temp;
//
//      /*--------------------- EXTI Mode Configuration ------------------------*/
//      /* Configure the External Interrupt or event for the current IO */
//      if((GPIO_Init->Mode & EXTI_MODE) == EXTI_MODE)
//      {
//        /* Enable SYSCFG Clock */
//        __HAL_RCC_SYSCFG_CLK_ENABLE();
//
//        temp = SYSCFG->EXTICR[position >> 2U];
//        temp &= ~(0x0FU << (4U * (position & 0x03U)));
//        temp |= ((uint32_t)(GPIO_GET_INDEX(GPIOx)) << (4U * (position & 0x03U)));
//        SYSCFG->EXTICR[position >> 2U] = temp;
//
//        /* Clear EXTI line configuration */
//        temp = EXTI->IMR;
//        temp &= ~((uint32_t)iocurrent);
//        if((GPIO_Init->Mode & GPIO_MODE_IT) == GPIO_MODE_IT)
//        {
//          temp |= iocurrent;
//        }
//        EXTI->IMR = temp;
//
//        temp = EXTI->EMR;
//        temp &= ~((uint32_t)iocurrent);
//        if((GPIO_Init->Mode & GPIO_MODE_EVT) == GPIO_MODE_EVT)
//        {
//          temp |= iocurrent;
//        }
//        EXTI->EMR = temp;
//
//        /* Clear Rising Falling edge configuration */
//        temp = EXTI->RTSR;
//        temp &= ~((uint32_t)iocurrent);
//        if((GPIO_Init->Mode & RISING_EDGE) == RISING_EDGE)
//        {
//          temp |= iocurrent;
//        }
//        EXTI->RTSR = temp;
//
//        temp = EXTI->FTSR;
//        temp &= ~((uint32_t)iocurrent);
//        if((GPIO_Init->Mode & FALLING_EDGE) == FALLING_EDGE)
//        {
//          temp |= iocurrent;
//        }
//        EXTI->FTSR = temp;
//      }
//    }
//  }
//}
