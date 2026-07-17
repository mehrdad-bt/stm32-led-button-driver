#include "app.h"



void App_init(App_t *app)
{
	app->button.port = GPIOB;
	app->button.pin = GPIO_PIN_13;
	app->button.last_state = false;
	app->button.last_press_time = 0;
}

void App_Process(App_t *app, Event_t event)
{
	
	  if( event == BUTTON_PRESSED)
		{
			
		switch (app->led.mode)
		{
			case MODE_OFF:	
			{
				
				Led_setMode(&app->led, MODE_BLINK);				
		  }
			break;
			
			case MODE_BLINK:
			{
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
	
	
	
	
	
	
	
	
	


	


