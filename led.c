#include "led.h"



void Led_toggle(Led_t *led)
{
	HAL_GPIO_TogglePin(led->port, led->pin);
}

void Led_off(Led_t *led)
{
	HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_RESET);
}

void Led_setMode(Led_t *led, LedMode_t led_mode)
{
	  if(led->mode != led_mode)
    {
        led->mode = led_mode;
        Timer_start(&led->timer, led->blinkPeriod);
    }
}

void Led_update(Led_t *led)
{
	
	switch (led->mode)
	{
		case MODE_OFF:
		{
			Led_off(led);
		}
		break;
		
		case MODE_BLINK:
		{
     if(Timer_expired(&led->timer))
			{
				Led_toggle(led);
			}
		}
		break;
		
		case MODE_FAST:
		{
     if(Timer_expired(&led->timer))
			{
				Led_toggle(led);
			}
		}
		
		break;
		
	}
	
}

