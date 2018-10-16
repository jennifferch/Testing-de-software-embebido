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
    gpio_clr_gpio_pin_Expect(LEDG);
    at45dbx_mem_check_IgnoreAndReturn(true);

    printk_IgnoreAndReturn(0);
    gpio_set_gpio_pin_Expect(LEDG);
    gpio_clr_gpio_pin_Expect(LEDB);

    TEST_ASSERT_EQUAL(0, mem_check());

}

void test_WhenInitSystem_ThenMemoryFail(void)
{
    gpio_clr_gpio_pin_Expect(LEDG);
    at45dbx_mem_check_IgnoreAndReturn(false);

    printk_IgnoreAndReturn(0);
    gpio_clr_gpio_pin_Expect(LEDR);
    gpio_set_gpio_pin_Expect(LEDG);

    TEST_ASSERT_EQUAL(1, mem_check());

}

void test_WhenRunDebug_ThenflashInitOK(void)
{
   gpio_set_gpio_pin_Expect(AT45DBX_CHIP_RESET);
   at45dbx_init_IgnoreAndReturn(true);
   TEST_ASSERT_EQUAL(0, flash_init(0));
}

void test_WhenRunDebug_ThenflashInitFail(void)
{
   gpio_set_gpio_pin_Expect(AT45DBX_CHIP_RESET);
   at45dbx_init_IgnoreAndReturn(true);
   TEST_ASSERT_EQUAL(1, flash_init(1));
}

void test_WhenFirmataIsNotDownload_ThenInit(void)
{
   nvram_init_IgnoreAndReturn(0);
   TEST_ASSERT_EQUAL(0, fw_download_init());
}

void test_WhenFirmataIsNotDownload_ThenFlashWrite(void)
{
   uint32_t sector = 36;
   uint32_t len = 4;
   uint8_t buf = 36;

   at45dbx_write_open_IgnoreAndReturn(true);
   at45dbx_write_byte_IgnoreAndReturn(true);
   at45dbx_write_close_IgnoreAndReturn(true);
   TEST_ASSERT_EQUAL(0, flash_write(sector, &buf, len));
  
}

void test_WhenFirmataIsDownload_ThenFlashRead(void)
{
   uint32_t sector = 36;
   uint32_t len = 4;
   uint8_t buf = 36;
   uint8_t bt = 7;

   at45dbx_read_open_IgnoreAndReturn(true);
   at45dbx_read_byte_IgnoreAndReturn(bt);
   at45dbx_read_close_IgnoreAndReturn(true);
   TEST_ASSERT_EQUAL(0, flash_read(sector, &buf, len));
  
}
