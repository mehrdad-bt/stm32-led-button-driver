#include "led.h"


void Led_init(Led_t *led)
{
		led->port = GPIOB;
	  led->pin = GPIO_PIN_12;
		led->mode = MODE_OFF;
		led->timer.start_timer = 0;
		led->timer.period = 0;
		led->blinkPeriod = 0;
}


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
		switch(led_mode)
		{
		case MODE_OFF:
				break;

		case MODE_BLINK:
				led->blinkPeriod = 500;
				break;

		case MODE_FAST:
				led->blinkPeriod = 300;
				break;
		}
		
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

