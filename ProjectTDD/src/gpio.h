#include "peripheral_map.h"

#ifndef _GPIO_H_
#define _GPIO_H_

typedef struct
{
  unsigned char pin;              //!< Module pin.
  unsigned char function;         //!< Module function.
} gpio_map_t[];

void gpio_enable_gpio_pin(unsigned int pin);
void gpio_set_gpio_pin(unsigned int pin);
void gpio_clr_gpio_pin(unsigned int pin);
void gpio_tgl_gpio_pin(unsigned int pin);

#endif  // _GPIO_H_
