/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  CMock_Init(); \
  UNITY_CLR_DETAILS(); \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
    CMock_Verify(); \
  } \
  CMock_Destroy(); \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#ifdef __WIN32__
#define UNITY_INCLUDE_SETUP_STUBS
#endif
#include "unity.h"
#include "cmock.h"
#ifndef UNITY_EXCLUDE_SETJMP_H
#include <setjmp.h>
#endif
#include <stdio.h>
#include "mock_printf-stdarg.h"
#include "mock_at45dbx.h"
#include "mock_gpio.h"
#include "mock_nvram.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_WhenInitSystem_ThenMemoryOK(void);
extern void test_WhenInitSystem_ThenMemoryFail(void);
extern void test_WhenRunDebug_ThenflashInitOK(void);
extern void test_WhenRunDebug_ThenflashInitFail(void);
extern void test_WhenFirmataIsNotDownload_ThenInit(void);
extern void test_WhenFirmataIsNotDownload_ThenFlashWrite(void);
extern void test_WhenFirmataIsDownload_ThenFlashRead(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_printf_stdarg_Init();
  mock_at45dbx_Init();
  mock_gpio_Init();
  mock_nvram_Init();
}
static void CMock_Verify(void)
{
  mock_printf_stdarg_Verify();
  mock_at45dbx_Verify();
  mock_gpio_Verify();
  mock_nvram_Verify();
}
static void CMock_Destroy(void)
{
  mock_printf_stdarg_Destroy();
  mock_at45dbx_Destroy();
  mock_gpio_Destroy();
  mock_nvram_Destroy();
}

/*=======Suite Setup=====*/
static void suite_setup(void)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  suiteSetUp();
#endif
}

/*=======Suite Teardown=====*/
static int suite_teardown(int num_failures)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  return suiteTearDown(num_failures);
#else
  return num_failures;
#endif
}

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  suite_setup();
  UnityBegin("test_flashFirmata.c");
  RUN_TEST(test_WhenInitSystem_ThenMemoryOK, 26);
  RUN_TEST(test_WhenInitSystem_ThenMemoryFail, 41);
  RUN_TEST(test_WhenRunDebug_ThenflashInitOK, 57);
  RUN_TEST(test_WhenRunDebug_ThenflashInitFail, 67);
  RUN_TEST(test_WhenFirmataIsNotDownload_ThenInit, 76);
  RUN_TEST(test_WhenFirmataIsNotDownload_ThenFlashWrite, 82);
  RUN_TEST(test_WhenFirmataIsDownload_ThenFlashRead, 98);

  CMock_Guts_MemFreeFinal();
  return suite_teardown(UnityEnd());
}
