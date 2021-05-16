//bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number x 4)
#define P_BAND_BASE 0x42000000
//byte_offset = byte_address - 0x40000000

#define RCC_AHB1ENR_0 (*((unsigned int*)(P_BAND_BASE + (0x23830*32))))
#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_MODER_10 (*(unsigned int*)(P_BAND_BASE + (0x20000*32) + (10*4)))
#define GPIOA_ODR_5    (*(unsigned int*)(P_BAND_BASE + (0x20014*32) + (5*4)))
#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

volatile int counter=0;

void main(void)
{
    RCC_AHB1ENR = 0x0;
    GPIOA_MODER = 0x0;
    //Enable clock for AHB1
    RCC_AHB1ENR_0  = 0x1;
    //Set Port5 as output
    GPIOA_MODER_10 = 0x1;

    while(1)
    {
    counter=0;

    while (counter < 1000000)
    {
      counter++;
    }
    //Turn bit 5 on
    GPIOA_ODR_5    = 0x1;
        
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
    //Turn bit 5 off
    GPIOA_ODR_5    = 0x0;

    }
}
