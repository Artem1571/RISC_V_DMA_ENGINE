#include "uart.h"
#include "dma.h"
#include <stdint.h>
#include <stdio.h>
#define N 32 
#define RAND_MAX 32767 
#define MAX_RAND_NUMBER 10
#define DMA_CTRL_DONE 0x40000000
int str2[32];

static unsigned long int next = 1;

int rand()
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % (RAND_MAX + 1);
}

/*генерация ПСП*/
void generate_prs (int *str, int n, int r)
{
    for (int i = 0; i < n; ++i) 
        str[i] = rand() % r;
}

/*Проверка корректной заполняемости*/
int check_pattern (int *data1, int *data2, int n)
{
	for (int i = 0; i < n; ++i) {
		if (data1[i] != data2[i])
			return 0;
	}
	return 1;		
}
	
int main()
{   
	int str1[N];
	generate_prs(str1, N, MAX_RAND_NUMBER);
	uart_init();
    dma_init();
    dma_start_transfer_i(str1, str2, N);
    
    volatile uint32_t *control = (uint32_t*)DMA_CONTROL; 
    while (*control & DMA_CTRL_DONE == 0);
    
	int result = check_pattern(str1, str2, N);
	if (result) 
		print("Data is valid\n"); 
	else
		print("ERROR DATA\n");
	return 0;
}