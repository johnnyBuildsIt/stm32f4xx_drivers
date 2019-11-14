#include <stm32f407xx.h>
#include <stm32f407xx_gpio_driver.h>

void delay(void) {
	for (uint32_t i = 0; i < 500000; i++);
}

int main (void) {
	GPIO_Handle_t gpioLed;

	gpioLed.pGPIOx = GPIOD;
	gpioLed.GPIO_PinConfig.GPIO_PinNumber = 12;
	gpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	gpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Init(&gpioLed);

	while(1) {
		GPIO_ToggleOutputPin(GPIOD, 12);
		delay();
	}

	return 0;

}
