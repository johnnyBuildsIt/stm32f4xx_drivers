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
	uint8_t GPIO_PinMode;			// @GPIO_PIN_MODES
	uint8_t GPIO_PinSpeed;			// @GPIO_PIN_SPEEDS
	uint8_t GPIO_PinPuPdControl;	// @GPIO_PIN_PUPD
	uint8_t GPIO_PinOPType;			// @GPIO_PIN_OUTPUT_TYPE
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/*
 * Handle structure for a GPIO pin
 */

typedef struct {
	GPIO_RegDef_t *pGPIOx; // base address of the GPIO peripheral
	GPIO_PinConfig_t GPIO_PinConfig; // GPIO pin configuration settings
}GPIO_Handle_t;

// @GPIO_PIN_MODES
// GPIO pin possible modes for MODER
#define GPIO_MODE_INPUT 					0
#define GPIO_MODE_OUTPUT 					1
#define GPIO_MODE_ALTFN 					2
#define GPIO_MODE_ANALOG 					3
#define GPIO_MODE_FALLING_EDGE_TRIGGER		4
#define GPIO_MODE_RISING_EDGE_TRIGGER		5
#define GPIO_MODE_RISING_FALLING_TRIGGER 	6

// @GPIO_PIN_OUTPUT_TYPE
// GPIO possible output types for OTYPER
#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

// @GPIO_PIN_SPEEDS
// GPIO possible output speeds for OSPEEDR
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

// @GPIO_PIN_PUPD
// GPIO possible pu/pd configs for PUPDR
#define GPIO_NO_PUPD	0
#define	GPIO_PU			1
#define GPIO_PD			2


/*
 * APIs supported by this driver
 * for more info, check function definitions
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);//use periph reset rcc register
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t enOrDi);// enable/disable clock for given base address
	void enable_GPIO_Clk(GPIO_RegDef_t *pGPIOx);
	void disable_GPIO_Clk(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
void GPIO_IRQConfig(uint8_t iRQNumber, uint8_t iRQPriority, uint8_t enOrDi);
void GPIO_IRQHandling(uint8_t pinNumber);


#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
