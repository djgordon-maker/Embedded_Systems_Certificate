#include "stm32f401xe.h"

#define RCC_AHB1ENR_OFFSET     ((unsigned int)(&RCC->AHB1ENR)-PERIPH_BASE)
#define GPIOA_MODER_OFFSET     ((unsigned int)(&GPIOA->MODER)-PERIPH_BASE)
#define GPIOA_ODR_OFFSET       ((unsigned int)(&GPIOA->ODR)-PERIPH_BASE)

#define RCC_AHB1ENR_GPIOAEN_bb (*(unsigned int*)(PERIPH_BB_BASE + (RCC_AHB1ENR_OFFSET*32) + (RCC_AHB1ENR_GPIOAEN_Pos*4)))
#define GPIOA_MODER_MODE5_bb   (*(unsigned int*)(PERIPH_BB_BASE + (GPIOA_MODER_OFFSET*32) + (GPIO_MODER_MODE5_Pos*4)))
#define GPIOA_ODR_OD5_bb       (*(unsigned int*)(PERIPH_BB_BASE + (GPIOA_ODR_OFFSET*32) + (GPIO_ODR_OD5_Pos*4)))

void delay(unsigned int wait){
  while(wait>0) { wait--; }
}
int main()
{
  RCC_AHB1ENR_GPIOAEN_bb = 0x1;
  GPIOA_MODER_MODE5_bb = 0x1;
  
  while(1) {
    GPIOA_ODR_OD5_bb = 0x1;
    delay(10000);
    GPIOA_ODR_OD5_bb = 0x0;
    delay(10000);
  }
  return 0;
}
