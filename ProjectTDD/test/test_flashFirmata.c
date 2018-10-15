#include "unity.h"
#include "flashFirmata.h"

#include "mock_printf-stdarg.h"
#include "mock_at45dbx.h"
#include "mock_gpio.h"

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
