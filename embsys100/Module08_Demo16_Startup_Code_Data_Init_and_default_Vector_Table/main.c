#include "stdint.h"
#include "delay.h"

#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

//typedef __packed struct {
typedef struct {
    uint16_t x;
    uint8_t y;
} Point;

typedef struct {
    Point bottom_left;
    Point top_right;    
} Rectangle;

typedef struct {
    Point corners[3];
} Triangle;

// ****************** Initialized ****************** 
Point p1 = {
    12,
    17
};

Rectangle r1 = {
    {1, 1},
    {5, 5}
};

Triangle t1 = {
    { {1, 1}, {2, 2}, {3, 3}}
};


int16_t myArray1[] = {1, 2, 3, 4, 5};


// ****************** Uninitialized ****************** 
Point* p2;
Rectangle r2;
Triangle t2;
int16_t myArray2[5];

void main(void)
{
    p1.x = sizeof(Point);
    p1.y = 'C';
       
    r1.bottom_left.x = 1;
    r1.bottom_left.y = 1;
    r1.top_right.x = 5;
    r1.top_right.x = 5;
    
    t1.corners[0].x = 1;
    t1.corners[0].y = 1;
    
    t1.corners[1].x = 3;
    t1.corners[1].y = 4;
    
    t1.corners[2].x = 5;
    t1.corners[2].y = 1;

    for(int i= 0; i < sizeof(myArray1)/sizeof(myArray1[0]); i++)
    {
        myArray1[i] = 'a' + i;
    }

    // ***********************
    p2 = &p1;    
    p2->x = sizeof(p1);
    (*p2).y = 34;

    r2.bottom_left.x = 1;
    r2.bottom_left.y = 1;
    r2.top_right.x = 5;
    r2.top_right.x = 5;
    
    t2.corners[0].x = 1;
    t2.corners[0].y = 1;
    
    t2.corners[1].x = 3;
    t2.corners[1].y = 4;
    
    t2.corners[2].x = 5;
    t2.corners[2].y = 1;
        
    for(int i= 0; i < sizeof(myArray2)/sizeof(myArray2[0]); i++)
    {
        myArray2[i] = 'a' + i;
    }
    // ***********************

    // RCC Base Address: 0x40023800
    // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
    // Address offset: 0x30
    // Set bit[0] to 1
    // 1. Enable clock to Peripheral
    RCC_AHB1ENR |= 0x1;
  
    // GPIOA Base Address: 0x40020000
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // Address offset: 0x00
    // Set bit[11:10] to 0x01  so --> 0x400 // To enable Port5 as output
    GPIOA_MODER |= 0x400;

    // GPIOA Base Address: 0x40020000
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x00; // Turn LED OFF
     
    while(1)
    {
        delay(1000000);
        GPIOA_ODR |= GPIOA;
            
        delay(1000000);
        GPIOA_ODR &= ~GPIOA;
    }
}
