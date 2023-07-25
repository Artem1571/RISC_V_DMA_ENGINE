#ifndef DMA_H
#define DMA_H

#include <stdint.h>

#define DMA_BASE        0x03000000
#define DMA_CONTROL     (DMA_BASE + 0x000)
#define DMA_NEXT_CONFIG (DMA_BASE + 0x004)
#define DMA_NEXT_BYTES  (DMA_BASE + 0x008)
#define DMA_NEXT_DST    (DMA_BASE + 0x010)
#define DMA_NEXT_SRC    (DMA_BASE + 0x018)

#define DMA_CTRL_CLAIM 1
#define DMA_CTRL_RUN 2
#define riscv_size_integer 4

void dma_init();
void dma_start_transfer_i(uint32_t *src, uint32_t *dst, int len);

#endif