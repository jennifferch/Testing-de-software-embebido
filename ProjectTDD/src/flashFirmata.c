#include "flashFirmata.h"

#include <string.h>
#include "printf-stdarg.h"
#include "at45dbx.h"
#include "gpio.h"
#include "nvram.h"

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

int flash_init(int spiOptions)
{
        /* put up flash reset pin */
        gpio_set_gpio_pin(AT45DBX_CHIP_RESET);
      
	if(spiOptions == 0)
	{
        
	   at45dbx_init(spiOptions, 0);
	}
        else
	{
	   return 1;
	}
        
   return 0;
}

int fw_download_init(void)
{
        nvram_init();
        return 0;
}

int flash_write(uint32_t  addr, const uint8_t* buf, uint32_t len)
{
        uint32_t sector = addr / AT45DBX_SECTOR_SIZE;
        uint32_t i;
        
        at45dbx_write_open(sector);
        for (i = 0; i < len; i++)
                at45dbx_write_byte(buf[i]);
        at45dbx_write_close();

   return 0;
}


int flash_read(uint32_t addr, uint8_t* buf, uint32_t len)
{
        uint32_t sector = addr / AT45DBX_SECTOR_SIZE;
        uint32_t i;
       
        at45dbx_read_open(sector);
        for (i = 0; i < len; i++)
                buf[i] = at45dbx_read_byte();
        at45dbx_read_close();
   return 0;
}











