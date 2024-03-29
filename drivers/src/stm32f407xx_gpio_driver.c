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
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){// non-interrupt mode
		registerState = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pinNumber);// clear before setting
		pGPIOHandle->pGPIOx->MODER |= registerState;
	} else {
		// interrupt mode
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_FALLING_EDGE_TRIGGER) {
			// 1. configure FTSR
			EXTI->FTSR |= (1 << pinNumber);
			// clear corresponding RTSR bit
			EXTI->RTSTR &= ~(1 << pinNumber);
		} else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_RISING_EDGE_TRIGGER) {
			// 1. configure RTSR
			EXTI->RTSTR |= (1 << pinNumber);
			// clear corresponding FTSR bit
			EXTI->FTSR &= ~(1 << pinNumber);
		} else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_RISING_FALLING_TRIGGER) {
			// 1. configure both FTSR and RTSR
			EXTI->FTSR |= (1 << pinNumber);
			EXTI->RTSTR |= (1 << pinNumber);
		}

		// 2. configure the GPIO port selection in SYSCFG_EXTICR
		uint8_t extiRegisterIndex = pinNumber / 4;
		uint8_t extiRegisterShiftAmt = pinNumber % 4;
		uint8_t portCode = EXTI_GPIO_PORT_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[extiRegisterIndex] = portCode << (extiRegisterShiftAmt * 4);

		// 3. enable the exti interrupt deliver using IMR(interrupt mask register)
		EXTI->IMR |= (1 << pinNumber);
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
void GPIO_IRQInterruptConfig(uint8_t iRQNumber, uint8_t enOrDi){
	if(enOrDi == ENABLE) {
		if(iRQNumber <= 31) {
			// ISER0 register
			*NVIC_ISER0 |= (1 << iRQNumber);
		} else if(iRQNumber > 31 && iRQNumber < 64) {
			// ISER1 register
			*NVIC_ISER1 |= (1 << (iRQNumber % 32));
		} else if(iRQNumber >= 64 && iRQNumber < 96) {
			// ISER2 register
			*NVIC_ISER2 |= (1 << (iRQNumber % 64));
		}
	} else {
		if(iRQNumber <= 31) {
			*NVIC_ICER0 |= (1 << iRQNumber);
		} else if(iRQNumber > 31 && iRQNumber < 64) {
			*NVIC_ICER1 |= (1 << (iRQNumber % 32));
		} else if(iRQNumber >= 64 && iRQNumber < 96) {
			*NVIC_ICER2 |= (1 << (iRQNumber % 64));
		}
	}
}

void GPIO_IRQPriorityConfig(uint8_t iRQNumber, uint8_t iRQPriority) {
	uint8_t iprxRegister = iRQNumber / 4;
	uint8_t iprxRegisterSection = iRQNumber % 4;
	uint8_t shiftAmount = (iprxRegisterSection * 8) + (4);// +4 b/c bottom four bits are not implemented
	*(NVIC_PR_BASE_ADDR + iprxRegister) |= (iRQPriority << shiftAmount);
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
	// clear the exti pr register corresponding to the pin number
	if(EXTI->PR & (1 << pinNumber)) {
		// clear
		EXTI->PR |= (1 << pinNumber);
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
