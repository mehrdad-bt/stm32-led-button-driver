#include "app.h"
#include "led.h"
#include "types.h"
#include "uart.h"

void Scheduler_init(void);
void Scheduler_Run(void);
static void Scheduler_ButtonTask(void);
static void Scheduler_AppTask(void);
static void Scheduler_LedTask(void);
