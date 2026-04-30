#ifndef BSP_H
#define BSP_H

#define HWREG(x) (*((volatile uint32_t *) (x)))

#define RCC_BASE (0x40021000U)

#define RCC_OFFSETAPB2ENR (0x18U) 

#define RCC_OFFSETAPB1RSTR (0x010U)

#define GPIOA_BASE (0x40010800U)

#define GPIOC_BASE (0x40011000U)


#define GPIO_OFFSETCRH (0x04U)

#define GPIO_OFFSETCRL (0x00U)

#define GPIO_OFFSETODR (0x0CU)

#define GPIO_OFFSETIDR (0x08U)



#endif
