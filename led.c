#include "led.h"



void Led_toggle(Led_t *led)
{
	HAL_GPIO_TogglePin(led->port, led->pin);
}

void Led_off(Led_t *led)
{
	HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
}
