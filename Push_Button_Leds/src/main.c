#include <stdint.h>
#include "bsp.h"

#define LED (13)
#define LED2 (6)
#define LED3 (7)
#define BUTTON1 (9)
#define BUTTON2 (10)
#define BUTTON3 (15)

int main(void){
    // CLOCKS C e A
    HWREG(RCC_BASE + RCC_OFFSETAPB2ENR) |= (1 << 4);
    HWREG(RCC_BASE + RCC_OFFSETAPB2ENR) |= (1 << 2);

    HWREG(RCC_BASE + RCC_OFFSETAPB1RSTR) |= (1 << 2);

    // LED PC13 
    HWREG(GPIOC_BASE + GPIO_OFFSETCRH) &= ~(0xF << (20));
    HWREG(GPIOC_BASE + GPIO_OFFSETCRH) |= (0x2 << (20));

    // LED A7 
    HWREG(GPIOA_BASE + GPIO_OFFSETCRL) &= ~(0xF << (28));
    HWREG(GPIOA_BASE + GPIO_OFFSETCRL) |= (0x2 << (28));

    // LED A6 
    HWREG(GPIOA_BASE + GPIO_OFFSETCRL) &= ~(0xF << (24));
    HWREG(GPIOA_BASE + GPIO_OFFSETCRL) |= (0x2 << (24));

    // BUTTON1 PA9 
    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) &= ~(0xF << (4));
    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) |= (0x8 << (4));
    HWREG(GPIOA_BASE + GPIO_OFFSETODR) |= (1 << BUTTON1);

    // BUTTON2 PA10 
    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) &= ~(0xF << (8));
    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) |= (0x8 << (8));
    HWREG(GPIOA_BASE + GPIO_OFFSETODR) |= (1 << BUTTON2);

    // BUTTON3 PA15 
    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) &= ~(0xF << (28));
    HWREG(GPIOA_BASE + GPIO_OFFSETCRH) |= (0x8 << (28));
    HWREG(GPIOA_BASE + GPIO_OFFSETODR) |= (1 << BUTTON3);

    while(1){
        if(((HWREG(GPIOA_BASE + GPIO_OFFSETIDR) & (1 << BUTTON1)) == 0)){
            HWREG(GPIOC_BASE + GPIO_OFFSETODR) &= ~(1 << LED);
        }else HWREG(GPIOC_BASE + GPIO_OFFSETODR) |= (1 << LED);

        if(((HWREG(GPIOA_BASE + GPIO_OFFSETIDR) & (1 << BUTTON2)) == 0)){
            HWREG(GPIOA_BASE + GPIO_OFFSETODR) |= (1 << LED2); 
        }else HWREG(GPIOA_BASE + GPIO_OFFSETODR) &= ~(1 << LED2);

        if(((HWREG(GPIOA_BASE + GPIO_OFFSETIDR) & (1 << BUTTON3)) == 0)){
            HWREG(GPIOA_BASE + GPIO_OFFSETODR) |= (1 << LED3); 
        }else HWREG(GPIOA_BASE + GPIO_OFFSETODR) &= ~H(1 << LED3);
    }
}