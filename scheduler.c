#include "scheduler.h"

static App_t app;

void Scheduler_init(void)
{
	App_init(&app);
	Led_init(&app.led);
}

static void Scheduler_ButtonTask(void)
{
    app.button.event = Button_update(&app.button);
}

static void Scheduler_AppTask(void)
{
    App_Process(&app, app.button.event);
}

static void Scheduler_LedTask(void)
{
    Led_update(&app.led);
}


void Scheduler_Run(void)
{
	Scheduler_ButtonTask();
	Scheduler_AppTask();
	Scheduler_LedTask();
}

