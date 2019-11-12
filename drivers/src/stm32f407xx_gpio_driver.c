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
	switch (pGPIOx) {
		case GPIOA:
			GPIOA_PCLK_EN();
			break;
		case GPIOB:
			GPIOB_PCLK_EN();
			break;
		case GPIOC:
			GPIOC_PCLK_EN();
			break;
		case GPIOD:
			GPIOD_PCLK_EN();
			break;
		case GPIOE:
			GPIOD_PCLK_EN();
			break;
		case GPIOF:
			GPIOF_PCLK_EN();
			break;
		case GPIOG:
			GPIOG_PCLK_EN();
			break;
		case GPIOH:
			GPIOH_PCLK_EN();
			break;
		case GPIOI:
			GPIOI_PCLK_EN();
			break;
	}
}

void GPIO_PeriClockDisableHelper(GPIO_RegDef_t *pGPIOx){
	switch(pGPIOx){
		case GPIOA:
			GPIOA_PCLK_DI();
			break;
		case GPIOB:
			GPIOB_PCLK_DI();
			break;
		case GPIOC:
			GPIOC_PCLK_DI();
			break;
		case GPIOD:
			GPIOD_PCLK_DI();
			break;
		case GPIOE:
			GPIOE_PCLK_DI();
			break;
		case GPIOF:
			GPIOF_PCLK_DI();
			break;
		case GPIOG:
			GPIOG_PCLK_DI();
			break;
		case GPIOH:
			GPIOH_PCLK_DI();
			break;
		case GPIOI:
			GPIOI_PCLK_DI();
			break;
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
