/*
 * stm32f407xx.h
 *
 *  Created on: Nov 9, 2019
 *      Author: Johnny Rutkowski
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

/*
 *  base address of Flash and SRAM memory
 */

#define FLASH_BASEADDR				0X08000000U	/*  */
#define SRAM1_BASEADDR				0X20000000U
#define SRAM2_BASEADDR				0x2001C000U
#define ROM_BASEADDR				0x1FFF0000U
#define SRAM_BASEADDR				SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base address
 * AHB - high speed data communication periph
 * APB - low speed data communication periph
 */

#define PERIPH_BASEADDR				0x40000000U
#define APB1PERIPH_BASEADDR			PERIPH_BASE
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR			0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0X0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0X1C00)
#define GPIOI_BASEADDR				(AHB1PERIPH_BASEADDR + 0X2000)
#define GPIOJ_BASEADDR				(AHB1PERIPH_BASEADDR + 0X2400)
#define GPIOK_BASEADDR				(AHB1PERIPH_BASEADDR + 0X2800)
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0X3800)

/*
 * Base addresses of peripherals which are hanging on APB1 bus
 */

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0X3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0X3C00)
#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0X4400)
#define USART3_BASEADDR				(APB1PERIPH_BASEADDR + 0X4800)
#define UART4_BASEADDR				(APB1PERIPH_BASEADDR + 0X4C00)
#define UART5_BASEADDR				(APB1PERIPH_BASEADDR + 0X5000)
#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0X5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0X5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0X5C00)

/*
 * Base addresses of peripherals which are hanging on APB2 bus
 */

#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0X1000)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0X1400)
#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0X3000)
#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0X3800)
#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0X3C00)

/*************Peripheral Register Definition Structures***********/

typedef struct {
	volatile uint32_t MODER;		// offset 0x00
	volatile uint32_t OTYPER;		// offset 0x04
	volatile uint32_t OSPEEDR;		// offset 0x08
	volatile uint32_t PUPDR;		// offset 0x0C
	volatile uint32_t IDR;			// offset 0x10
	volatile uint32_t ODR;			// offset 0x14
	volatile uint32_t BSRR;			// offset 0x18
	volatile uint32_t LCKR;			// offset 0x1C
	volatile uint32_t AFRL;			// offset 0x20
	volatile uint32_t AFRH;			// offset 0x24
}GPIO_RegDef_t;

typedef struct {
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_PLLCFGR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_AHB1RSTR;
	volatile uint32_t RCC_AHB2RSTR;
	volatile uint32_t RCC_AHB3RSTR;
	uint32_t		  RESERVED0;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_APB2RSTR;
	uint32_t		  RESERVED1;
	uint32_t		  RESERVED2;
	volatile uint32_t RCC_AHB1ENR;
	volatile uint32_t RCC_AHB2ENR;
	volatile uint32_t RCC_AHB3ENR;
	uint32_t		  RESERVED3;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_APB2ENR;
	uint32_t		  RESERVED4;
	uint32_t		  RESERVED5;
	volatile uint32_t RCC_AHB1LPENR;
	volatile uint32_t RCC_AHB2LPENR;
	volatile uint32_t RCC_AHB3LPENR;
	uint32_t		  RESERVED6;
	volatile uint32_t RCC_APB1LPENR;
	volatile uint32_t RCC_APB2LPENR;
	uint32_t		  RESERVED7;
	uint32_t		  RESERVED8;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	uint32_t		  RESERVED9;
	uint32_t		  RESERVED10;
	volatile uint32_t RCC_SSCGR;
	volatile uint32_t RCC_PLLI2SCFGR;
}RCC_RegDef_t;

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;


typedef struct {
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	uint32_t 		  RESERVED0;
	uint32_t 		  RESERVED1;
	volatile uint32_t CMPCR;

}SYSCFG_RegDef_t;

/*************Peripheral Definitions***********/
/*peripheral base addresses type casted to xxx_RegDef_t*/

#define GPIOA		((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB		((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC		((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD		((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE		((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF		((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG		((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH		((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI		((GPIO_RegDef_t*) GPIOI_BASEADDR)
#define GPIOJ		((GPIO_RegDef_t*) GPIOJ_BASEADDR)
#define GPIOK		((GPIO_RegDef_t*) GPIOK_BASEADDR)

#define RCC			((RCC_RegDef_t*) RCC_BASEADDR)

#define EXTI		((EXTI_RegDef_t*) EXTI_BASEADDR)

#define SYSCFG		((SYSCFG_RegDef_t*) SYSCFG_BASEADDR)

/*
 * Clock enable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 8))
//#define GPIOJ_PCLK_EN()			(RCC->AHB1ENR |= (1 << 9))
//#define GPIOK_PCLK_EN()			(RCC->AHB1ENR |= (1 << 10))

/*
 * Clock enable macros for I2Cx peripherals
 */



/*
 * Clock enable macros for SPIx peripherals
 */



/*
 * Clock enable macros for USARTx peripherals
 */



/*
 * Clock enable macros for SYSCFGx peripherals
 */
#define SYSCFG_PCLK_EN()		(RCC->RCC_APB2ENR |= (1 << 14))


/*
 * Clock disable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 8))

// GPIOx peripheral reset
#define GPIOA_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 0)); (RCC->RCC_AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 1)); (RCC->RCC_AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 2)); (RCC->RCC_AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 3)); (RCC->RCC_AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 4)); (RCC->RCC_AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 5)); (RCC->RCC_AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 6)); (RCC->RCC_AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 7)); (RCC->RCC_AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()		do{ (RCC->RCC_AHB1RSTR |= (1 << 8)); (RCC->RCC_AHB1RSTR &= ~(1 << 8)); }while(0)

#define EXTI_GPIO_PORT_CODE(x)	((x == GPIOA)?0:\
								 (x == GPIOB)?1:\
								 (x == GPIOC)?2:\
								 (x == GPIOD)?3:\
								 (x == GPIOE)?4:\
							     (x == GPIOF)?5:\
							     (x == GPIOG)?6:\
								 (x == GPIOH)?7:0)

// some generic macros
#define ENABLE 		1
#define DISABLE 	0
#define SET 		ENABLE
#define RESET 		DISABLE


#endif /* INC_STM32F407XX_H_ */





























