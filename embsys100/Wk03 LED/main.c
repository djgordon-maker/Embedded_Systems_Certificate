#define RCC_BASE    0x40023800
#define RCC_AHB1ENR (*((unsigned int*) 0x40023830))
#define GPIOA_BASE  0x40020000
#define GPIOA_MODER (*((unsigned int*) GPIOA_BASE))
#define GPIOA_ODR   (*((unsigned int*) 0x40020014))
int counter = 0;

int main()
{
  RCC_AHB1ENR |= 0x1;
  GPIOA_MODER |= 0x400;
  while(1) {
    counter = 0;
    while(counter < 1000000) { counter++; }
    GPIOA_ODR |= 0x20;
    counter = 0;
    while(counter < 1000000) { counter++; }
    GPIOA_ODR &= ~0x20;
  }
  return 0;
}
