#ifndef UART_H
#define UART_H

#include <stdint.h>

#define UART_BASE   0x10010000
#define TX 	   (UART_BASE + 0x00)
#define CTRL   (UART_BASE + 0x08)
#define UART_TX_FULL 0x80000000

void uart_init();
void uart_putchar(char data);
void print(const char *str);

#endif 
