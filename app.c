#include "app.h"



void App_init(App_t *app)
{
	app->led.port = GPIOB;
	app->led.pin = GPIO_PIN_12;
	app->button.port = GPIOB;
	app->button.pin = GPIO_PIN_13;
	app->mode = MODE_OFF;
	app->timer.start_timer = 0;
	app->timer.period = 0;
	app->button.last_state = false;
	app->button.last_press_time = 0;
	app->timer.running = false;
	app->timer.f_running = false;

}

void App_Process(App_t *app)
{
	
 	if( Button_update(&app->button) )
	{
		switch (app->mode)
		{
			case MODE_OFF:
			{
				app->mode = MODE_BLINK;
			
		  }
			break;
			
			case MODE_BLINK:
			{
				app->mode = MODE_FAST;
				
			}
			
			break;
			
			case MODE_FAST:
			{
				app->mode = MODE_OFF;
			}
			break;
		}
	}
	
	switch (app->mode)
	{
		case MODE_OFF:
		{
			Led_off(&app->led);
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
				Led_toggle(&app->led);
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
	


