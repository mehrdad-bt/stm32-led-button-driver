#pragma once
#include "stm32f1xx_hal.h"
#include <stdbool.h>

typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
	bool last_state;
	uint32_t last_press_time;
}Button_t;



typedef enum{
	MODE_OFF,
	MODE_BLINK,
	MODE_FAST
}LedMode_t;

typedef struct{
	uint32_t start_timer;
	uint32_t period;
	bool running;
	bool f_running;
}Timer_t;


typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
	LedMode_t mode;
}Led_t;

typedef struct{
	Led_t led;
	Button_t button;
	Timer_t timer;
}App_t;

