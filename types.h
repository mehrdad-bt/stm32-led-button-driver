#pragma once
#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef enum{
	BUTTON_PRESSED,
	BUTTON_RELEASED
}Event_t;


typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
	bool last_state;
	uint32_t last_press_time;
	Event_t event;
}Button_t;



typedef enum{
	MODE_OFF,
	MODE_BLINK,
	MODE_FAST
}LedMode_t;

typedef struct{
	uint32_t start_timer;
	uint32_t period;
}Timer_t;


typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
	LedMode_t mode;
	Timer_t timer;
	uint32_t blinkPeriod;
}Led_t;

typedef struct{
	 UART_HandleTypeDef *huart;
	 Timer_t timer;
}Uart_t;


typedef struct{
	Led_t led;
	Button_t button;
	Uart_t uart;
}App_t;




