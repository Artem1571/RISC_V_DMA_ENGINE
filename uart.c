#include <stdint.h>

#include "uart.h"

void uart_init()
{
	*(uint32_t*)(CTRL) = 1;
}
/*передача по UART*/
void uart_putchar(char data)
{	
	volatile int32_t *tx = (int32_t*)(TX);
	while ((*tx & UART_TX_FULL));
	*tx = data;
} 

void print(const char *str)
{
	for (int i = 0; str[i] != 0; i++)
		uart_putchar(str[i]);
}



