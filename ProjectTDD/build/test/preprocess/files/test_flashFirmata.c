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

    char msg[20] = "Memory check OK";



    gpio_clr_gpio_pin_CMockExpect(30, LEDG);

    at45dbx_mem_check_CMockExpectAndReturn(31, 

   1

   );



    gpio_set_gpio_pin_CMockExpect(33, LEDG);

    gpio_clr_gpio_pin_CMockExpect(34, LEDB);

    printk_CMockExpectAndReturn(35, msg, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenInitSystem_ThenMemoryFail(void)

{



    char msg[20] = "Memory check fail";



    gpio_clr_gpio_pin_CMockExpect(46, LEDG);

    at45dbx_mem_check_CMockExpectAndReturn(47, 

   0

   );



    gpio_clr_gpio_pin_CMockExpect(49, LEDR);

    gpio_set_gpio_pin_CMockExpect(50, LEDG);

    printk_CMockExpectAndReturn(51, msg, 0);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((mem_check())), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenRunDebug_ThenflashInitOK(void)

{

   int spiOption = 0;



   gpio_set_gpio_pin_CMockExpect(61, AT45DBX_CHIP_RESET);

   at45dbx_init_CMockExpectAndReturn(62, spiOption, 0, 

  1

  );



   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((flash_init(spiOption))), (

  ((void *)0)

  ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenRunDebug_ThenflashInitFail(void)

{

   int spiOption = 1;



   gpio_set_gpio_pin_CMockExpect(71, AT45DBX_CHIP_RESET);



   UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((flash_init(spiOption))), (

  ((void *)0)

  ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenFirmataIsNotDownload_ThenInit(void)

{

   nvram_init_CMockExpectAndReturn(78, 0);

   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((fw_download_init())), (

  ((void *)0)

  ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

}



void test_WhenFirmataIsNotDownload_ThenFlashWrite(void)

{

   uint32_t sector = 36 / (1 << 8);

   uint8_t buf[4] = {2, 4, 6, 8};

   uint32_t i;



   at45dbx_write_open_CMockExpectAndReturn(88, sector, 

  1

  );

   for (i = 0; i < 4; i++)

      at45dbx_write_byte_CMockExpectAndReturn(90, buf[i], 

     1

     );



   at45dbx_write_close_CMockExpectAndReturn(92, 

  1

  );



   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((flash_write(sector, buf, 4))), (

  ((void *)0)

  ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);



}



void test_WhenFirmataIsDownload_ThenFlashRead(void)

{

   uint32_t sector = 36 / (1 << 8);

   uint8_t buf[4] = {12, 14, 16, 18};



   uint32_t i;



   at45dbx_read_open_CMockExpectAndReturn(105, sector, 

  1

  );

   for (i = 0; i < 4; i++)

      at45dbx_read_byte_CMockExpectAndReturn(107, buf[i]);



   at45dbx_read_close_CMockExpectAndReturn(109, 

  1

  );

   UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((flash_read(sector, buf, 4))), (

  ((void *)0)

  ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_INT);



}
