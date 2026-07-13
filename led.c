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
	led->mode = led_mode;
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
			 if(!app->timer.running)
			 {
				 Timer_start(&app->timer , 500);
				 app->timer.running = true;
			 }	
			if( Timer_expired(&app->timer) )
			{
				Led_toggle(led);
				Timer_start(&app->timer, 500);
			}
		}
		break;
		
		case MODE_FAST:
		{
			if(!app->timer.f_running)
			{ 
			  Timer_start(&app->timer, 200);
				app->timer.f_running = true;
			}
			if( Timer_expired(&app->timer) )
			{
				Led_toggle(&app->led);
				Timer_start(&app->timer, 200);
			}
		}
		break;
		
	}
	
}