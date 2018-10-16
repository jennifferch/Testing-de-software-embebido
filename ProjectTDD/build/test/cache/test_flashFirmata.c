#include "build/temp/_test_flashFirmata.c"
#include "mock_nvram.h"
#include "mock_gpio.h"
#include "mock_at45dbx.h"
#include "mock_printf-stdarg.h"
#include "flashFirmata.h"
#include "unity.h"








void setUp(void)

{

   gpio_enable_gpio_pin_CMockExpect(13, LEDG);

   gpio_enable_gpio_pin_CMockExpect(14, LEDR);

   gpio_enable_gpio_pin_CMockExpect(15, LEDB);

   gpio_set_gpio_pin_CMockExpect(16, LEDG);

   gpio_set_gpio_pin_CMockExpect(17, LEDR);

   gpio_set_gpio_pin_CMockExpect(18, LEDB);

   led_init();

}



void tearDown(void)

{

}



void test_WhenInitSystem_ThenMemoryOK(void)

{

    gpio_clr_gpio_pin_CMockExpect(28, LEDG);

    at45dbx_mem_check_CMockIgnoreAndReturn(29, 

   1

   );



    printk_CMockIgnoreAndReturn(31, 0);

    gpio_set_gpio_pin_CMockExpect(32, LEDG);

    gpio_clr_gpio_pin_CMockExpect(33, LEDB);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenInitSystem_ThenMemoryFail(void)

{

    gpio_clr_gpio_pin_CMockExpect(41, LEDG);

    at45dbx_mem_check_CMockIgnoreAndReturn(42, 

   0

   );



    printk_CMockIgnoreAndReturn(44, 0);

    gpio_clr_gpio_pin_CMockExpect(45, LEDR);

    gpio_set_gpio_pin_CMockExpect(46, LEDG);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenRunDebug_ThenflashInitOK(void)

{

   gpio_set_gpio_pin_CMockExpect(54, AT45DBX_CHIP_RESET);

   at45dbx_init_CMockIgnoreAndReturn(55, 

  1

  );

   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((flash_init(0))), (

  ((void *)0)

  ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenRunDebug_ThenflashInitFail(void)

{

   gpio_set_gpio_pin_CMockExpect(61, AT45DBX_CHIP_RESET);

   at45dbx_init_CMockIgnoreAndReturn(62, 

  1

  );

   UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((flash_init(1))), (

  ((void *)0)

  ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenFirmataIsNotDownload_ThenInit(void)

{

   nvram_init_CMockIgnoreAndReturn(68, 0);

   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((fw_download_init())), (

  ((void *)0)

  ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenFirmataIsNotDownload_ThenFlashWrite(void)

{

   uint32_t sector = 36;

   uint32_t len = 4;

   uint8_t buf = 36;



   at45dbx_write_open_CMockIgnoreAndReturn(78, 

  1

  );

   at45dbx_write_byte_CMockIgnoreAndReturn(79, 

  1

  );

   at45dbx_write_close_CMockIgnoreAndReturn(80, 

  1

  );

   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((flash_write(sector, &buf, len))), (

  ((void *)0)

  ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);



}
