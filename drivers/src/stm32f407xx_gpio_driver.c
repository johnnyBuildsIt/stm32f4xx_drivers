/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Johnny Rutkowski
 */

#include "stm32f407xx_gpio_driver.h"


/*
 * config structure for a GPIO pin
 */
typedef struct {
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/*
 * Handle structure for a GPIO pin
 */

typedef struct {
	// pointer to hold the base address of the GPIO peripheral
	GPIO_RegDef_t *pGPIOBx;
	// GPIO pin configuration settings
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;
