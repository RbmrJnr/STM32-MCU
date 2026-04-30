#include <stdint.h>

// simbolos la do linker.ld
extern uint32_t _estack;   
extern uint32_t _sidata;    
extern uint32_t _sdata;     
extern uint32_t _edata;    
extern uint32_t _sbss;      
extern uint32_t _ebss;      

/* Protótipos */
extern int main(void);
void Reset_Handler(void);

__attribute__((section(".vectors")))
uint32_t *g_pfnVectors[] = {
    (uint32_t *)&_estack,      // 0x00
    (uint32_t *)Reset_Handler, // 0x04
};


__attribute__((naked, noreturn))
void Reset_Handler(void) {
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    while (dst < &_edata) {
        *dst++ = *src++;
    }

    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    main();

    while (1);
}