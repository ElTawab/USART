#ifndef _USART_Interface_H_
#define _USART_Interface_H_

void UART_Init(void);

void UART_SendChar(u8 data);

u8 UART_GetChar(void);

#endif