#include "build/temp/_test_flashFirmata.c"
#include "mock_gpio.h"
#include "mock_at45dbx.h"
#include "mock_printf-stdarg.h"
#include "flashFirmata.h"
#include "unity.h"




void setUp(void)

{

   gpio_enable_gpio_pin_CMockExpect(10, LEDG);

   gpio_enable_gpio_pin_CMockExpect(11, LEDR);

   gpio_enable_gpio_pin_CMockExpect(12, LEDB);

   gpio_set_gpio_pin_CMockExpect(13, LEDG);

   gpio_set_gpio_pin_CMockExpect(14, LEDR);

   gpio_set_gpio_pin_CMockExpect(15, LEDB);

   led_init();

}



void tearDown(void)

{

}



void test_WhenInitSystem_ThenMemoryOK(void)

{

    gpio_clr_gpio_pin_CMockExpect(25, LEDG);

    at45dbx_mem_check_CMockIgnoreAndReturn(26, 

   1

   );



    printk_CMockIgnoreAndReturn(28, 0);

    gpio_set_gpio_pin_CMockExpect(29, LEDG);

    gpio_clr_gpio_pin_CMockExpect(30, LEDB);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenInitSystem_ThenMemoryFail(void)

{

    gpio_clr_gpio_pin_CMockExpect(38, LEDG);

    at45dbx_mem_check_CMockIgnoreAndReturn(39, 

   0

   );



    printk_CMockIgnoreAndReturn(41, 0);

    gpio_clr_gpio_pin_CMockExpect(42, LEDR);

    gpio_set_gpio_pin_CMockExpect(43, LEDG);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);



}
