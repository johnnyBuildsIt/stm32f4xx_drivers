/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Johnny Rutkowski
 */

#include "stm32f407xx_gpio_driver.h"

/*
 * Name: GPIO_Init
 *
 * Description: TODO fill in description
 *
 * Parameters:
 * 		pGPIOHandle - a struct containing the base addr of a GPIO port
 * 					  and the port config settings
 * Return: void
 *
 * Notes:
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t registerState = 0;
	uint8_t pinNumber = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;

	// 1. configure the mode of the gpio pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= 3){// non-interrupt mode
		registerState = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pinNumber);// clear before setting
		pGPIOHandle->pGPIOx->MODER |= registerState;
	} else {
		// interrupt mode
		// TODO implement interrupt mode
	}

	// 2. configure speed
	registerState = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pinNumber);// clear before setting
	pGPIOHandle->pGPIOx->OSPEEDR |= registerState;

	// 3. configure pupd (pull up/pull down
	registerState = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= (0x3 << pinNumber);// clear before setting
	pGPIOHandle->pGPIOx->PUPDR |= registerState;

	// 4. configure the optype (output type)
	registerState = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= registerState;

	// 5. configure alt functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
		// configure alternate function registers
		uint8_t afrLowOrHigh, afrShiftBy;

		afrLowOrHigh = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		afrShiftBy = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

		if(afrLowOrHigh == 1) {
			pGPIOHandle->pGPIOx->OTYPER &= ~(0xF << (4 * afrShiftBy));// clear before setting
			pGPIOHandle->pGPIOx->AFRH |= pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * afrShiftBy);
		} else {
			pGPIOHandle->pGPIOx->OTYPER &= ~(0xF << (4 * afrShiftBy));// clear before setting
			pGPIOHandle->pGPIOx->AFRL |= pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * afrShiftBy);
		}
	}
}

/*
 * Name: GPIO_DeInit
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA) {
			GPIOA_REG_RESET();
		} else if(pGPIOx == GPIOB) {
			GPIOB_REG_RESET();
		} else if(pGPIOx == GPIOC) {
			GPIOC_REG_RESET();
		} else if(pGPIOx == GPIOD) {
			GPIOD_REG_RESET();
		} else if(pGPIOx == GPIOE) {
			GPIOE_REG_RESET();
		} else if(pGPIOx == GPIOF) {
			GPIOF_REG_RESET();
		} else if(pGPIOx == GPIOG) {
			GPIOG_REG_RESET();
		} else if(pGPIOx == GPIOH) {
			GPIOH_REG_RESET();
		} else if(pGPIOx == GPIOI) {
			GPIOI_REG_RESET();
		}
}

/*
 * Name: GPIO_PeriClockControl
 *
 * Description: enables/disables peripheral clock for a given port
 *
 * Parameters:
 * 	pGPIOx - base address of a gpio peripheral
 * 	enOrDi - enable or disable macros
 *
 * Return: none
 *
 * Notes: none
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t enOrDi){
	if(enOrDi == ENABLE) {
		enable_GPIO_Clk(pGPIOx);
	} else {
		disable_GPIO_Clk(pGPIOx);
	}
}

void enable_GPIO_Clk(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA) {
		GPIOA_PCLK_EN();
	} else if(pGPIOx == GPIOB) {
		GPIOB_PCLK_EN();
	} else if(pGPIOx == GPIOC) {
		GPIOC_PCLK_EN();
	} else if(pGPIOx == GPIOD) {
		GPIOD_PCLK_EN();
	} else if(pGPIOx == GPIOE) {
		GPIOE_PCLK_EN();
	} else if(pGPIOx == GPIOF) {
		GPIOF_PCLK_EN();
	} else if(pGPIOx == GPIOG) {
		GPIOG_PCLK_EN();
	} else if(pGPIOx == GPIOH) {
		GPIOH_PCLK_EN();
	} else if(pGPIOx == GPIOI) {
		GPIOI_PCLK_EN();
	}
}

void disable_GPIO_Clk(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA) {
		GPIOA_PCLK_DI();
	} else if(pGPIOx == GPIOB) {
		GPIOB_PCLK_DI();
	} else if(pGPIOx == GPIOC) {
		GPIOC_PCLK_DI();
	} else if(pGPIOx == GPIOD) {
		GPIOD_PCLK_DI();
	} else if(pGPIOx == GPIOE) {
		GPIOE_PCLK_DI();
	} else if(pGPIOx == GPIOF) {
		GPIOF_PCLK_DI();
	} else if(pGPIOx == GPIOG) {
		GPIOG_PCLK_DI();
	} else if(pGPIOx == GPIOH) {
		GPIOH_PCLK_DI();
	} else if(pGPIOx == GPIOI) {
		GPIOI_PCLK_DI();
	}
}

/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber){
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> pinNumber) & 0x00000001);
	return value;
}

/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value){
	if(value == SET) {
		pGPIOx->ODR |= (value << pinNumber);
	} else {
		pGPIOx->ODR &= ~(1 << pinNumber);
	}

}

/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value){
	pGPIOx->ODR = value;
}

/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber){
	pGPIOx->ODR ^= (1 << pinNumber);
}

/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
void GPIO_IRQConfig(uint8_t iRQNumber, uint8_t iRQPriority, uint8_t enOrDi){

}

/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
void GPIO_IRQHandling(uint8_t pinNumber){

}



/*
 * Name:
 *
 * Description:
 *
 * Parameters:
 *
 * Return:
 *
 * Notes:
 */
