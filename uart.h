#include "types.h"
#include "timer.h"

void Uart_Init(Uart_t *, UART_HandleTypeDef *);

void Uart_SendByte();

void Uart_SendBuffer();

void Uart_SendString(Uart_t *, char *);

void Uart_ReadByte();