/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Nov 12, 2019
 *      Author: Johnny Rutkowski
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

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
	GPIO_RegDef_t *pGPIOBx; // pointer to hold the base address of the GPIO peripheral
	GPIO_PinConfig_t GPIO_PinConfig; // GPIO pin configuration settings
}GPIO_Handle_t;


/*
 * APIs supported by this driver
 * for more info, check function definitions
 */

void GPIO_Init(void);


#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */

























