#include "app.h"



void App_init(App_t *app)
{
	app->led.port = GPIOB;
	app->led.pin = GPIO_PIN_12;
	app->button.port = GPIOB;
	app->button.pin = GPIO_PIN_13;
	app->led.mode = MODE_OFF;
	app->led.timer.start_timer = 0;
	app->led.timer.period = 0;
	app->button.last_state = false;
	app->button.last_press_time = 0;
	app->led.blinkPeriod = 0;

}

void App_Process(App_t *app)
{
	
 	if( Button_update(&app->button) )
	{
		switch (app->led.mode)
		{
			case MODE_OFF:
			{
				app->led.blinkPeriod = 500;
				Led_setMode(&app->led, MODE_BLINK);				
		  }
			break;
			
			case MODE_BLINK:
			{
				app->led.blinkPeriod = 300;
				Led_setMode(&app->led, MODE_FAST);				
			}
			
			break;
			
			case MODE_FAST:
			{
				Led_setMode(&app->led, MODE_OFF);
			}
			break;
		}
	}
	
	
	
	
	
	
	
	
	
}
	


