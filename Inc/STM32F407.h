#ifndef _STM32F407_H_
#define _STM32F407_H_

#include <stdint.h>

typedef volatile int8_t vint8_t;
typedef volatile uint8_t vuint8_t;

typedef volatile int16_t vint16_t;
typedef volatile uint16_t vuint16_t;

typedef volatile int32_t vint32_t;
typedef volatile uint32_t vuint32_t;

struct GPIO_tag {
  union {
    vuint32_t R;
    struct {
    	vuint32_t MODER0:2;
    	vuint32_t MODER1:2;
    	vuint32_t MODER2:2;
    	vuint32_t MODER3:2;
    	vuint32_t MODER4:2;
    	vuint32_t MODER5:2;
    	vuint32_t MODER6:2;
    	vuint32_t MODER7:2;
    	vuint32_t MODER8:2;
    	vuint32_t MODER9:2;
    	vuint32_t MODER10:2;
    	vuint32_t MODER11:2;
    	vuint32_t MODER12:2;
    	vuint32_t MODER13:2;
    	vuint32_t MODER14:2;
    	vuint32_t MODER15:2;
    } B;
  } MODER;

  union {
	  vuint32_t R;
	  struct {
		vuint32_t OT0:1;
		vuint32_t OT1:1;
		vuint32_t OT2:1;
		vuint32_t OT3:1;
		vuint32_t OT4:1;
		vuint32_t OT5:1;
		vuint32_t OT6:1;
		vuint32_t OT7:1;
		vuint32_t OT8:1;
		vuint32_t OT9:1;
		vuint32_t OT10:1;
		vuint32_t OT11:1;
		vuint32_t OT12:1;
		vuint32_t OT13:1;
		vuint32_t OT14:1;
		vuint32_t OT15:1;
		vuint32_t :16;
	  } B;
	} OTYPER;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t OSPEEDR0:2;
		vuint32_t OSPEEDR1:2;
		vuint32_t OSPEEDR2:2;
		vuint32_t OSPEEDR3:2;
		vuint32_t OSPEEDR4:2;
		vuint32_t OSPEEDR5:2;
		vuint32_t OSPEEDR6:2;
		vuint32_t OSPEEDR7:2;
		vuint32_t OSPEEDR8:2;
		vuint32_t OSPEEDR9:2;
		vuint32_t OSPEEDR10:2;
		vuint32_t OSPEEDR11:2;
		vuint32_t OSPEEDR12:2;
		vuint32_t OSPEEDR13:2;
		vuint32_t OSPEEDR14:2;
		vuint32_t OSPEEDR15:2;
	  } B;
	} OSPEEDR;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t PUPDR0:2;
		vuint32_t PUPDR1:2;
		vuint32_t PUPDR2:2;
		vuint32_t PUPDR3:2;
		vuint32_t PUPDR4:2;
		vuint32_t PUPDR5:2;
		vuint32_t PUPDR6:2;
		vuint32_t PUPDR7:2;
		vuint32_t PUPDR8:2;
		vuint32_t PUPDR9:2;
		vuint32_t PUPDR10:2;
		vuint32_t PUPDR11:2;
		vuint32_t PUPDR12:2;
		vuint32_t PUPDR13:2;
		vuint32_t PUPDR14:2;
		vuint32_t PUPDR15:2;
	  } B;
	} PUPDR;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t IDR0:1;
		vuint32_t IDR1:1;
		vuint32_t IDR2:1;
		vuint32_t IDR3:1;
		vuint32_t IDR4:1;
		vuint32_t IDR5:1;
		vuint32_t IDR6:1;
		vuint32_t IDR7:1;
		vuint32_t IDR8:1;
		vuint32_t IDR9:1;
		vuint32_t IDR10:1;
		vuint32_t IDR11:1;
		vuint32_t IDR12:1;
		vuint32_t IDR13:1;
		vuint32_t IDR14:1;
		vuint32_t IDR15:1;
		vuint32_t :16;
	  } B;
	} IDR;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t ODR0:1;
		vuint32_t ODR1:1;
		vuint32_t ODR2:1;
		vuint32_t ODR3:1;
		vuint32_t ODR4:1;
		vuint32_t ODR5:1;
		vuint32_t ODR6:1;
		vuint32_t ODR7:1;
		vuint32_t ODR8:1;
		vuint32_t ODR9:1;
		vuint32_t ODR10:1;
		vuint32_t ODR11:1;
		vuint32_t ODR12:1;
		vuint32_t ODR13:1;
		vuint32_t ODR14:1;
		vuint32_t ODR15:1;
		vuint32_t :16;
	  } B;
	} ODR;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t BS0:1;
		vuint32_t BS1:1;
		vuint32_t BS2:1;
		vuint32_t BS3:1;
		vuint32_t BS4:1;
		vuint32_t BS5:1;
		vuint32_t BS6:1;
		vuint32_t BS7:1;
		vuint32_t BS8:1;
		vuint32_t BS9:1;
		vuint32_t BS10:1;
		vuint32_t BS11:1;
		vuint32_t BS12:1;
		vuint32_t BS13:1;
		vuint32_t BS14:1;
		vuint32_t BS15:1;
		vuint32_t BR0:1;
		vuint32_t BR1:1;
		vuint32_t BR2:1;
		vuint32_t BR3:1;
		vuint32_t BR4:1;
		vuint32_t BR5:1;
		vuint32_t BR6:1;
		vuint32_t BR7:1;
		vuint32_t BR8:1;
		vuint32_t BR9:1;
		vuint32_t BR10:1;
		vuint32_t BR11:1;
		vuint32_t BR12:1;
		vuint32_t BR13:1;
		vuint32_t BR14:1;
		vuint32_t BR15:1;
	  } B;
	} BSRR;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t LCK0:1;
		vuint32_t LCK1:1;
		vuint32_t LCK2:1;
		vuint32_t LCK3:1;
		vuint32_t LCK4:1;
		vuint32_t LCK5:1;
		vuint32_t LCK6:1;
		vuint32_t LCK7:1;
		vuint32_t LCK8:1;
		vuint32_t LCK9:1;
		vuint32_t LCK10:1;
		vuint32_t LCK11:1;
		vuint32_t LCK12:1;
		vuint32_t LCK13:1;
		vuint32_t LCK14:1;
		vuint32_t LCK15:1;
		vuint32_t LCKK:1;
		vuint32_t :15;
	  } B;
	} LCKR;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t AFRL0:4;
		vuint32_t AFRL1:4;
		vuint32_t AFRL2:4;
		vuint32_t AFRL3:4;
		vuint32_t AFRL4:4;
		vuint32_t AFRL5:4;
		vuint32_t AFRL6:4;
		vuint32_t AFRL7:4;
	  } B;
	} AFRL;

	union {
	  vuint32_t R;
	  struct {
		vuint32_t AFRH8:4;
		vuint32_t AFRH9:4;
		vuint32_t AFRH10:4;
		vuint32_t AFRH11:4;
		vuint32_t AFRH12:4;
		vuint32_t AFRH13:4;
		vuint32_t AFRH14:4;
		vuint32_t AFRH15:4;
	  } B;
	} AFRH;

};

struct RCC_tag {
	union {
		vuint32_t R;
		struct {
			vuint32_t HSION:1;
			vuint32_t HSIRDY:1;
			vuint32_t :1;
			vuint32_t HSITRIM0:1;
			vuint32_t HSITRIM1:1;
			vuint32_t HSITRIM2:1;
			vuint32_t HSITRIM3:1;
			vuint32_t HSITRIM4:1;
			vuint32_t HSICAL0:1;
			vuint32_t HSICAL1:1;
			vuint32_t HSICAL2:1;
			vuint32_t HSICAL3:1;
			vuint32_t HSICAL4:1;
			vuint32_t HSICAL5:1;
			vuint32_t HSICAL6:1;
			vuint32_t HSICAL7:1;
			vuint32_t HSEON:1;
			vuint32_t HSERDY:1;
			vuint32_t HSEBYP:1;
			vuint32_t CSSON:1;
			vuint32_t :4;
			vuint32_t PLLON:1;
			vuint32_t PLLRDY:1;
			vuint32_t PLLI2SON:1;
			vuint32_t PLLI2SRDY:1;
			vuint32_t :4;
		} B;
	} RCC_CR;

	union {
		vuint32_t R;
	} RCC_PLLCFGR;

	union {
		vuint32_t R;
	} RCC_CFGR;

	union {
		vuint32_t R;
	} RCC_CIR;

	union {
		vuint32_t R;
	} RCC_AHB1RSTR;

	union {
		vuint32_t R;
	} RCC_AHB2RSTR;

	union {
		vuint32_t R;
	} RCC_AHB3RSTR;

	uint8_t RCC_reserved0[4];

	union {
		vuint32_t R;
	} RCC_APB1RSTR;

	union {
		vuint32_t R;
	} RCC_APB2RSTR;

	uint8_t RCC_reserved1[4];

	uint8_t RCC_reserved2[4];

	union {
		vuint32_t R;
		struct {
			vuint32_t GPIOAEN:1;
			vuint32_t GPIOBEN:1;
			vuint32_t GPIOCEN:1;
			vuint32_t GPIODEN:1;
			vuint32_t GPIOEEN:1;
			vuint32_t GPIOFEN:1;
			vuint32_t GPIOGEN:1;
			vuint32_t GPIOHEN:1;
			vuint32_t GPIOIEN:1;
			vuint32_t :3;
			vuint32_t CRCEN:1;
			vuint32_t :5;
			vuint32_t BKPSRAMEN:1;
			vuint32_t :1;
			vuint32_t CCMDATARAMEN:1;
			vuint32_t DMA1EN:1;
			vuint32_t DMA2EN:1;
			vuint32_t :2;
			vuint32_t ETHMACEN:1;
			vuint32_t ETHMACTXEN:1;
			vuint32_t ETHMACRXEN:1;
			vuint32_t ETHMACPTPEN:1;
			vuint32_t OTGHSEN:1;
			vuint32_t OTGHSULPIEN:1;
			vuint32_t :1;
		} B;
	} RCC_AHB1ENR;

	union {
		vuint32_t R;
	} RCC_AHB2ENR;

	union {
		vuint32_t R;
	} RCC_AHB3ENR;

	uint8_t RCC_reserved3[4];

	union {
		vuint32_t R;
	} RCC_APB1ENR;

	union {
		vuint32_t R;
	} RCC_APB2ENR;

	uint8_t RCC_reserved4[4];

	uint8_t RCC_reserved5[4];

	union {
		vuint32_t R;
	} RCC_AHB1LPENR;

	union {
		vuint32_t R;
	} RCC_AHB2LPENR;

	union {
		vuint32_t R;
	} RCC_AHB3LPENR;

	uint8_t RCC_reserved6[4];

	union {
		vuint32_t R;
	} RCC_APB1LPENR;

	union {
		vuint32_t R;
	} RCC_APB2LPENR;

	uint8_t RCC_reserved7[4];

	uint8_t RCC_reserved8[4];

	union {
		vuint32_t R;
	} RCC_BDCR;

	union {
		vuint32_t R;
	} RCC_CSR;

	uint8_t RCC_reserved9[4];

	uint8_t RCC_reserved10[4];

	union {
		vuint32_t R;
	} RCC_SSCGR;

	union {
		vuint32_t R;
	} RCC_PLLI2SCFGR;
};


#define GPIOA ((volatile struct GPIO_tag *)(0x40020000UL))
#define GPIOB ((volatile struct GPIO_tag *)(0x40020400UL))
#define GPIOC ((volatile struct GPIO_tag *)(0x40020800UL))
#define GPIOD ((volatile struct GPIO_tag *)(0x40020C00UL))
#define GPIOE ((volatile struct GPIO_tag *)(0x40021000UL))
#define GPIOF ((volatile struct GPIO_tag *)(0x40021400UL))
#define GPIOG ((volatile struct GPIO_tag *)(0x40021800UL))
#define GPIOH ((volatile struct GPIO_tag *)(0x40021C00UL))
#define GPIOI ((volatile struct GPIO_tag *)(0x40022000UL))

#define RCC   ((volatile struct RCC_tag *)(0x40023800UL))





#endif // _STM32F407_H_
