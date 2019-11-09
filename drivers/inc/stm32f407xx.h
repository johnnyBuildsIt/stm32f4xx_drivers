/*
 * stm32f407xx.h
 *
 *  Created on: Nov 9, 2019
 *      Author: whenwhathuh
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
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
}GPIO_RegDef_t;

#endif /* INC_STM32F407XX_H_ */





























