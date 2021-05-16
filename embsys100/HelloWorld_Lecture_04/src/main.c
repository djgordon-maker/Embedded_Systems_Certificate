/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
	      

Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

uint32_t Fibonacci(uint32_t n) {
    if (n <= 1) {
        return 1;
    }
    uint32_t prev2 = 1;
    uint32_t prev1 = 1;
    uint32_t result;
    while (--n) {
         result = prev2 + prev1;
         prev2 = prev1;
         prev1 = result;
    }
    return result;
}

uint32_t Fibonacci2(uint32_t n) {
    if (n <= 1) {
        return 1;
    }
    uint32_t result = Fibonacci2(n-2) + Fibonacci2(n-1);
    return result;
}

/*******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
  uint8_t count;
  
  sqrAsm(&count);

  Hw_init();
  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  PrintString("[My name]'s Nucleo STM32F401 is ... alive!!!\n");
  RETAILMSG(1, ("Demo program Fall module 4: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));  

  for (count = 0; count < 50; count++) {
    uint32_t fib = Fibonacci(count);
    Print("fib[%lu] = %lu\n", count, fib);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
  };
              
  uint32_t testCnt = 0;
  while(1) {
      delay(1000);
      Print("wait %d\n", testCnt++);
  }

  /*
  for (count = 0; count < 50; count++) {
    uint32_t fib2 = Fibonacci2(count);
    Print("fib2[%lu] = %lu\n", count, fib2);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
  };
  */
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  