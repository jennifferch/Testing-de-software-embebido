/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_spi.h"

static const char* CMockString_delay = "delay";
static const char* CMockString_pcs_decode = "pcs_decode";
static const char* CMockString_spi = "spi";
static const char* CMockString_spi_enable = "spi_enable";
static const char* CMockString_spi_selectionMode = "spi_selectionMode";
static const char* CMockString_variable_ps = "variable_ps";

typedef struct _CMOCK_spi_selectionMode_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  int Expected_spi;
  unsigned char Expected_variable_ps;
  unsigned char Expected_pcs_decode;
  unsigned char Expected_delay;

} CMOCK_spi_selectionMode_CALL_INSTANCE;

typedef struct _CMOCK_spi_enable_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  int Expected_spi;

} CMOCK_spi_enable_CALL_INSTANCE;

static struct mock_spiInstance
{
  int spi_selectionMode_IgnoreBool;
  CMOCK_spi_selectionMode_CALLBACK spi_selectionMode_CallbackFunctionPointer;
  int spi_selectionMode_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE spi_selectionMode_CallInstance;
  int spi_enable_IgnoreBool;
  CMOCK_spi_enable_CALLBACK spi_enable_CallbackFunctionPointer;
  int spi_enable_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE spi_enable_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_spi_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.spi_selectionMode_IgnoreBool)
    Mock.spi_selectionMode_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_spi_selectionMode);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.spi_selectionMode_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.spi_selectionMode_CallbackFunctionPointer != NULL)
    Mock.spi_selectionMode_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.spi_enable_IgnoreBool)
    Mock.spi_enable_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_spi_enable);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.spi_enable_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.spi_enable_CallbackFunctionPointer != NULL)
    Mock.spi_enable_CallInstance = CMOCK_GUTS_NONE;
}

void mock_spi_Init(void)
{
  mock_spi_Destroy();
}

void mock_spi_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.spi_selectionMode_CallbackFunctionPointer = NULL;
  Mock.spi_selectionMode_CallbackCalls = 0;
  Mock.spi_enable_CallbackFunctionPointer = NULL;
  Mock.spi_enable_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void spi_selectionMode(int spi, unsigned char variable_ps, unsigned char pcs_decode, unsigned char delay)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_spi_selectionMode_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_spi_selectionMode);
  cmock_call_instance = (CMOCK_spi_selectionMode_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.spi_selectionMode_CallInstance);
  Mock.spi_selectionMode_CallInstance = CMock_Guts_MemNext(Mock.spi_selectionMode_CallInstance);
  if (Mock.spi_selectionMode_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.spi_selectionMode_CallbackFunctionPointer != NULL)
  {
    Mock.spi_selectionMode_CallbackFunctionPointer(spi, variable_ps, pcs_decode, delay, Mock.spi_selectionMode_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_spi_selectionMode,CMockString_spi);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_spi, spi, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_spi_selectionMode,CMockString_variable_ps);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_variable_ps, variable_ps, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_spi_selectionMode,CMockString_pcs_decode);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_pcs_decode, pcs_decode, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_spi_selectionMode,CMockString_delay);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_delay, delay, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_spi_selectionMode(CMOCK_spi_selectionMode_CALL_INSTANCE* cmock_call_instance, int spi, unsigned char variable_ps, unsigned char pcs_decode, unsigned char delay)
{
  cmock_call_instance->Expected_spi = spi;
  cmock_call_instance->Expected_variable_ps = variable_ps;
  cmock_call_instance->Expected_pcs_decode = pcs_decode;
  cmock_call_instance->Expected_delay = delay;
}

void spi_selectionMode_CMockIgnore(void)
{
  Mock.spi_selectionMode_IgnoreBool = (int)1;
}

void spi_selectionMode_CMockExpect(UNITY_LINE_TYPE cmock_line, int spi, unsigned char variable_ps, unsigned char pcs_decode, unsigned char delay)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_spi_selectionMode_CALL_INSTANCE));
  CMOCK_spi_selectionMode_CALL_INSTANCE* cmock_call_instance = (CMOCK_spi_selectionMode_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.spi_selectionMode_CallInstance = CMock_Guts_MemChain(Mock.spi_selectionMode_CallInstance, cmock_guts_index);
  Mock.spi_selectionMode_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_spi_selectionMode(cmock_call_instance, spi, variable_ps, pcs_decode, delay);
  UNITY_CLR_DETAILS();
}

void spi_selectionMode_StubWithCallback(CMOCK_spi_selectionMode_CALLBACK Callback)
{
  Mock.spi_selectionMode_IgnoreBool = (int)0;
  Mock.spi_selectionMode_CallbackFunctionPointer = Callback;
}

void spi_enable(int spi)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_spi_enable_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_spi_enable);
  cmock_call_instance = (CMOCK_spi_enable_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.spi_enable_CallInstance);
  Mock.spi_enable_CallInstance = CMock_Guts_MemNext(Mock.spi_enable_CallInstance);
  if (Mock.spi_enable_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (Mock.spi_enable_CallbackFunctionPointer != NULL)
  {
    Mock.spi_enable_CallbackFunctionPointer(spi, Mock.spi_enable_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_spi_enable,CMockString_spi);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_spi, spi, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_spi_enable(CMOCK_spi_enable_CALL_INSTANCE* cmock_call_instance, int spi)
{
  cmock_call_instance->Expected_spi = spi;
}

void spi_enable_CMockIgnore(void)
{
  Mock.spi_enable_IgnoreBool = (int)1;
}

void spi_enable_CMockExpect(UNITY_LINE_TYPE cmock_line, int spi)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_spi_enable_CALL_INSTANCE));
  CMOCK_spi_enable_CALL_INSTANCE* cmock_call_instance = (CMOCK_spi_enable_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.spi_enable_CallInstance = CMock_Guts_MemChain(Mock.spi_enable_CallInstance, cmock_guts_index);
  Mock.spi_enable_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_spi_enable(cmock_call_instance, spi);
  UNITY_CLR_DETAILS();
}

void spi_enable_StubWithCallback(CMOCK_spi_enable_CALLBACK Callback)
{
  Mock.spi_enable_IgnoreBool = (int)0;
  Mock.spi_enable_CallbackFunctionPointer = Callback;
}

