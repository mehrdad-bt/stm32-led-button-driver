#include "scheduler.h"

static App_t app;

void Scheduler_init(void)
{
	App_init(&app);
	Led_init(&app.led);
}

void Scheduler_Run(void)
{
	  Event_t event;
		event = Button_update(&app.button);
		App_Process(&app, event);
		Led_update(&app.led);
}

