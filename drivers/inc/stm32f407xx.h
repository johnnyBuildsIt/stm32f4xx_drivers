/*
 * stm32f407xx.h
 *
 *  Created on: Nov 9, 2019
 *      Author: whenwhathuh
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

/*
 *  base address of Flash and SRAM memory
 */

#define FLASH_BASEADDR				0X08000000U	/*  */
#define SRAM1_BASEADDR				0X20000000U
#define SRAM2_BASEADDR				0x2001C000U
#define ROM							0x1FFF0000U
#define SRAM						SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base address
 * AHB - high speed data communication periph
 * APB - low speed data communication periph
 */

#define PERIPH_BASEADDR				0x40000000U
#define APB1PERIPH_BASEADDR			PERIPH_BASE
#define APB2PERIPH_BASEADDR			0x400010000U
#define AHB1PERIPH_BASEADDR			0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U

#endif /* INC_STM32F407XX_H_ */
