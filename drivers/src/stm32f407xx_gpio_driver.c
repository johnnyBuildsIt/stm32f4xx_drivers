/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Johnny Rutkowski
 */

#include "stm32f407xx_gpio_driver.h"

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
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t temp = 0;
	uint8_t pinNumber = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;

	// 1. configure the mode of the gpio pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= 3){// non-interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pinNumber));
		pGPIOHandle->pGPIOx->MODER = temp;
	} else {
		// interrupt mode
		// TODO implement interrupt mode
	}

	// 2. configure speed

	// 3. configure pupd (pull up/pull down

	// 4. configure the optype (output type)

	// 5. configure alt functionality
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
		GPIO_PeriClockEnableHelper(pGPIOx);
	} else {
		GPIO_PeriClockDisableHelper(pGPIOx);
	}
}

void GPIO_PeriClockEnableHelper(GPIO_RegDef_t *pGPIOx){
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

void GPIO_PeriClockDisableHelper(GPIO_RegDef_t *pGPIOx){
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
	return 0;
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
	return 0;
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
