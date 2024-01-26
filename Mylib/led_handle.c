#include "led_handle.h"
#include "stm32f1xx_hal.h"
void led_handle(int index, int state)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0<<index, (GPIO_PinState)state);
}
