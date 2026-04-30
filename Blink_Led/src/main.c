#include <stdint.h>
#include "../bsp/bsp.h"

#define LED (10)

int main(void){
    HWREG(RCC_BASE + RCC_OFFSETAPB2ENR) |= (1 << 4);

    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) &= ~(0xF << (8));

    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) |= (0x2 << (8));

    while(1){
        HWREG(GPIOA_BASE + GPIO_OFFSETODR) ^= (1 << LED);

        for(volatile int i = 0; i < 500000; i++);
    }
    
}