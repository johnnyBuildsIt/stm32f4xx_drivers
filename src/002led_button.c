/*
 * 002led_button.c
 *
 *  Created on: Nov 15, 2019
 *      Author: whenwhathuh
 */

#include <stm32f407xx.h>
#include <stm32f407xx_gpio_driver.h>

void delay(void) {
	for (uint32_t i = 0; i < 250000; i++);
}

int main (void) {
	GPIO_Handle_t gpioLed, gpioBtn;

	gpioLed.pGPIOx = GPIOD;
	gpioLed.GPIO_PinConfig.GPIO_PinNumber = 12;
	gpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	gpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Init(&gpioLed);

	gpioBtn.pGPIOx = GPIOA;
	gpioBtn.GPIO_PinConfig.GPIO_PinNumber = 0;
	gpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	gpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&gpioBtn);

	while(1) {
		if(GPIO_ReadFromInputPin(GPIOA, 0)){
			delay(); // debounce
			GPIO_ToggleOutputPin(GPIOD, 12);
		}

	}

	return 0;

}
