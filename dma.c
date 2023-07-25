#include "dma.h"
#include <stdint.h>

void dma_init() 
{
    *(uint32_t*)DMA_CONTROL  = DMA_CTRL_CLAIM;   
}
/*запуск передачи DMA*/
void dma_start_transfer_i(uint32_t *src, uint32_t *dst, int len)
{
    *(uint32_t*)DMA_NEXT_BYTES = len*riscv_size_integer;
    *(uint32_t**)DMA_NEXT_DST = dst;
    *(uint32_t**)DMA_NEXT_SRC = src;
    *(uint32_t*)DMA_CONTROL |= DMA_CTRL_RUN;
}

