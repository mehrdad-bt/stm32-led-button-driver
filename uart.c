#include "uart.h"



void Uart_Init(Uart_t *uart, UART_HandleTypeDef *huart)
{
	uart->huart = huart;
	Timer_start(&uart->timer, 1000);
}

void Uart_SendString(Uart_t *uart, char *str)
{
	    if (uart == NULL || uart->huart == NULL || str == NULL)
        return;
	
	
			
	     if(Timer_expired(&uart->timer))
			{
				HAL_UART_Transmit(uart->huart, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
			}		
			
	
	
}

	

