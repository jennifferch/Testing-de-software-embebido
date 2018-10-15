#include "peripheral_map.h"








typedef struct

{

  unsigned char pin;

  unsigned char function;

} gpio_map_t[];



void gpio_enable_gpio_pin(unsigned int pin);

void gpio_set_gpio_pin(unsigned int pin);

void gpio_clr_gpio_pin(unsigned int pin);

void gpio_tgl_gpio_pin(unsigned int pin);
