#include "STD_TYPES.h"
#include "bit.h"
#include"USART_Register.h"
#include"USART_Config.h"
void UART_Init(void)
{
  // Set BaudRate -> 9600/8MhZ
  UBRRL = 51;
  UBRRH = 0;
  // Set Frame Format -> 8 data, 1 stop, No Parity
  UCSRC = 0b10000110;
  // Enable RX and TX
  UCSRB = 0b11111000;
}

void UART_SendChar(u8 data)
{
  // Wait until transmission Register Empty
  while(!get_bit(UCSRA,UDRE));
  UDR = data;
}

u8 UART_GetChar(void)
{
  u8 Result;
  // Wait until Reception Complete
  while(!get_bit(UCSRA,RXC));
  Result = UDR;
  
  /* Clear Flag */
  set_bit(UCSRA,7);
  return Result;
  
}

