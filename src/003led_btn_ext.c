/*
 * 003led_btn_ext.c
 *
 *  Created on: Nov 16, 2019
 *      Author: whenwhathuh
 */

/*
 * 002led_button.c
 *
 *  Created on: Nov 15, 2019
 *      Author: whenwhathuh
 */

#include <stm32f407xx.h>
#include <stm32f407xx_gpio_driver.h>

void delay(void) {
	for (uint32_t i = 0; i < 500000; i++);
}

int main (void) {
	GPIO_Handle_t gpioLed, gpioBtn;

	gpioLed.pGPIOx = GPIOA;
	gpioLed.GPIO_PinConfig.GPIO_PinNumber = 8;
	gpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	gpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&gpioLed);

	gpioBtn.pGPIOx = GPIOB;
	gpioBtn.GPIO_PinConfig.GPIO_PinNumber = 12;
	gpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	gpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);

	GPIO_Init(&gpioBtn);

	while(1) {
		if(!GPIO_ReadFromInputPin(GPIOB, 12)){
			delay(); // debounce
			GPIO_ToggleOutputPin(GPIOA, 8);
		}

	}

	return 0;

}

