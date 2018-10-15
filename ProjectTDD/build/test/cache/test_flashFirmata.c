#include "build/temp/_test_flashFirmata.c"
#include "mock_nvram.h"
#include "mock_gpio.h"
#include "mock_at45dbx.h"
#include "mock_printf-stdarg.h"
#include "flashFirmata.h"
#include "unity.h"




void setUp(void)

{

   gpio_enable_gpio_pin_CMockExpect(11, LEDG);

   gpio_enable_gpio_pin_CMockExpect(12, LEDR);

   gpio_enable_gpio_pin_CMockExpect(13, LEDB);

   gpio_set_gpio_pin_CMockExpect(14, LEDG);

   gpio_set_gpio_pin_CMockExpect(15, LEDR);

   gpio_set_gpio_pin_CMockExpect(16, LEDB);

   led_init();

}



void tearDown(void)

{

}



void test_WhenInitSystem_ThenMemoryOK(void)

{

    gpio_clr_gpio_pin_CMockExpect(26, LEDG);

    at45dbx_mem_check_CMockIgnoreAndReturn(27, 

   1

   );



    printk_CMockIgnoreAndReturn(29, 0);

    gpio_set_gpio_pin_CMockExpect(30, LEDG);

    gpio_clr_gpio_pin_CMockExpect(31, LEDB);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenInitSystem_ThenMemoryFail(void)

{

    gpio_clr_gpio_pin_CMockExpect(39, LEDG);

    at45dbx_mem_check_CMockIgnoreAndReturn(40, 

   0

   );



    printk_CMockIgnoreAndReturn(42, 0);

    gpio_clr_gpio_pin_CMockExpect(43, LEDR);

    gpio_set_gpio_pin_CMockExpect(44, LEDG);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenRunDebug_ThenflashInitOK(void)

{

   gpio_set_gpio_pin_CMockExpect(52, AT45DBX_CHIP_RESET);

   at45dbx_init_CMockIgnoreAndReturn(53, 

  1

  );

   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((flash_init(0))), (

  ((void *)0)

  ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenRunDebug_ThenflashInitFail(void)

{

   gpio_set_gpio_pin_CMockExpect(59, AT45DBX_CHIP_RESET);

   at45dbx_init_CMockIgnoreAndReturn(60, 

  1

  );

   UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((flash_init(1))), (

  ((void *)0)

  ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenFirmataIsNotDownload_ThenInit(void)

{

   nvram_init_CMockIgnoreAndReturn(66, 0);

   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((fw_download_init())), (

  ((void *)0)

  ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}
