#include "gpio.h"

volatile unsigned int* gpio_fs1 = (unsigned int*)(GPIO_BASE+0x04);
volatile unsigned int* gpio_fs4 = (unsigned int*)(GPIO_BASE+0x10);


volatile unsigned int* gpio;
volatile unsigned int tim;
int kmain(void)
{
  /* Assign the address of the GPIO peripheral (Using ARM Physical Address) */
  gpio = (unsigned int*)GPIO_BASE;

  /* Write 1 to the GPIO16 init nibble in the Function Select 1 GPIO
     peripheral register to enable GPIO16 as an output */
  gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);

  /* Never exit as there is no OS to exit to! */
  while(1)
  {
      for(tim = 0; tim < 500000; tim++);

      /* Set the LED GPIO pin low ( Turn OK LED on for original Pi, and off
         for plus models )*/
      gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);

      for(tim = 0; tim < 500000; tim++);

      /* Set the LED GPIO pin high ( Turn OK LED off for original Pi, and on
         for plus models )*/
      gpio[LED_GPSET] = (1 << LED_GPIO_BIT);
  }

    return 0;
}

// void exit(int code)
// {
//     while(1)
//         ;
// }
