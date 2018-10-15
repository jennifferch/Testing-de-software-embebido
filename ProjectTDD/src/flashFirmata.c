#include "flashFirmata.h"

#include <string.h>
#include "printf-stdarg.h"
#include "at45dbx.h"
#include "gpio.h"

#define GREEN_OFF() 		gpio_set_gpio_pin(LEDG)
#define GREEN_ON() 			gpio_clr_gpio_pin(LEDG)
#define GREEN_BLINK() 		gpio_tgl_gpio_pin(LEDG)
#define RED_OFF() 			gpio_set_gpio_pin(LEDR)
#define RED_ON() 			gpio_clr_gpio_pin(LEDR)
#define RED_BLINK() 		gpio_tgl_gpio_pin(LEDR)
#define BLUE_OFF() 			gpio_set_gpio_pin(LEDB)
#define BLUE_ON() 			gpio_clr_gpio_pin(LEDB)
#define BLUE_BLINK() 		gpio_tgl_gpio_pin(LEDB)


void led_init(void)
{
	gpio_enable_gpio_pin(LEDG);
	gpio_enable_gpio_pin(LEDR);
	gpio_enable_gpio_pin(LEDB);
	GREEN_OFF();
	RED_OFF();
	BLUE_OFF();
}


int mem_check(void)
{
        GREEN_ON();

        if (at45dbx_mem_check())
        {
                GREEN_OFF();
                BLUE_ON();
        	printk("Memory check OK");
        }
        else
        {
        	RED_ON();
        	GREEN_OFF();
        	printk("Memory check fail");
        	return 1;
        }
        return 0;
}










