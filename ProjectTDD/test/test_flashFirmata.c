#include "unity.h"
#include "flashFirmata.h"

#include "mock_printf-stdarg.h"
#include "mock_at45dbx.h"
#include "mock_gpio.h"
#include "mock_nvram.h"

#include <stdint.h>

void setUp(void)
{
   gpio_enable_gpio_pin_Expect(LEDG);
   gpio_enable_gpio_pin_Expect(LEDR);
   gpio_enable_gpio_pin_Expect(LEDB);
   gpio_set_gpio_pin_Expect(LEDG);
   gpio_set_gpio_pin_Expect(LEDR);
   gpio_set_gpio_pin_Expect(LEDB);
   led_init();
}

void tearDown(void)
{
}

void test_WhenInitSystem_ThenMemoryOK(void)
{
    char msg[20] = "Memory check OK";

    gpio_clr_gpio_pin_Expect(LEDG);
    at45dbx_mem_check_ExpectAndReturn(true);

    gpio_set_gpio_pin_Expect(LEDG);
    gpio_clr_gpio_pin_Expect(LEDB);
    printk_ExpectAndReturn(msg, 0);

    TEST_ASSERT_EQUAL(0, mem_check());

}

void test_WhenInitSystem_ThenMemoryFail(void)
{
    
    char msg[20] = "Memory check fail";

    gpio_clr_gpio_pin_Expect(LEDG);
    at45dbx_mem_check_ExpectAndReturn(false);

    gpio_clr_gpio_pin_Expect(LEDR);
    gpio_set_gpio_pin_Expect(LEDG);
    printk_ExpectAndReturn(msg, 0);

    TEST_ASSERT_EQUAL(1, mem_check());

}

void test_WhenRunDebug_ThenflashInitOK(void)
{
   int spiOption = 0;

   gpio_set_gpio_pin_Expect(AT45DBX_CHIP_RESET);
   at45dbx_init_ExpectAndReturn(spiOption,0,true);

   TEST_ASSERT_EQUAL(0, flash_init(spiOption));
}

void test_WhenRunDebug_ThenflashInitFail(void)
{
   int spiOption = 1;

   gpio_set_gpio_pin_Expect(AT45DBX_CHIP_RESET);

   TEST_ASSERT_EQUAL(1, flash_init(spiOption));
}

void test_WhenFirmataIsNotDownload_ThenInit(void)
{
   nvram_init_ExpectAndReturn(0);
   TEST_ASSERT_EQUAL(0, fw_download_init());
}

void test_WhenFirmataIsNotDownload_ThenFlashWrite(void)
{
   uint32_t sector = 36 / AT45DBX_SECTOR_SIZE;
   uint8_t buf[MAX_SIZE] = {2, 4, 6, 8};
   uint32_t i;

   at45dbx_write_open_ExpectAndReturn(sector,true);
   for (i = 0; i < MAX_SIZE; i++)
      at45dbx_write_byte_ExpectAndReturn(buf[i],true);

   at45dbx_write_close_ExpectAndReturn(true);

   TEST_ASSERT_EQUAL(0, flash_write(sector, buf, MAX_SIZE));
  
}

void test_WhenFirmataIsDownload_ThenFlashRead(void)
{
   uint32_t sector = 36 / AT45DBX_SECTOR_SIZE;
   uint8_t buf[MAX_SIZE] = {12, 14, 16, 18};
 
   uint32_t i;

   at45dbx_read_open_ExpectAndReturn(sector,true);
   for (i = 0; i < MAX_SIZE; i++)
      at45dbx_read_byte_ExpectAndReturn(buf[i]);

   at45dbx_read_close_ExpectAndReturn(true);
   TEST_ASSERT_EQUAL(0, flash_read(sector, buf, MAX_SIZE));
  
}
