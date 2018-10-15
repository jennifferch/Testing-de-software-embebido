/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_at45dbx.h"

static const char* CMockString_at45dbx_mem_check = "at45dbx_mem_check";

typedef struct _CMOCK_at45dbx_mem_check_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  _Bool ReturnVal;
  int CallOrder;

} CMOCK_at45dbx_mem_check_CALL_INSTANCE;

static struct mock_at45dbxInstance
{
  int at45dbx_mem_check_IgnoreBool;
  _Bool at45dbx_mem_check_FinalReturn;
  CMOCK_at45dbx_mem_check_CALLBACK at45dbx_mem_check_CallbackFunctionPointer;
  int at45dbx_mem_check_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE at45dbx_mem_check_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_at45dbx_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.at45dbx_mem_check_IgnoreBool)
    Mock.at45dbx_mem_check_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_at45dbx_mem_check);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.at45dbx_mem_check_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.at45dbx_mem_check_CallbackFunctionPointer != NULL)
    Mock.at45dbx_mem_check_CallInstance = CMOCK_GUTS_NONE;
}

void mock_at45dbx_Init(void)
{
  mock_at45dbx_Destroy();
}

void mock_at45dbx_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.at45dbx_mem_check_CallbackFunctionPointer = NULL;
  Mock.at45dbx_mem_check_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

_Bool at45dbx_mem_check(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_at45dbx_mem_check_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_at45dbx_mem_check);
  cmock_call_instance = (CMOCK_at45dbx_mem_check_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.at45dbx_mem_check_CallInstance);
  Mock.at45dbx_mem_check_CallInstance = CMock_Guts_MemNext(Mock.at45dbx_mem_check_CallInstance);
  if (Mock.at45dbx_mem_check_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.at45dbx_mem_check_FinalReturn;
    memcpy(&Mock.at45dbx_mem_check_FinalReturn, &cmock_call_instance->ReturnVal, sizeof(_Bool));
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.at45dbx_mem_check_CallbackFunctionPointer != NULL)
  {
    return Mock.at45dbx_mem_check_CallbackFunctionPointer(Mock.at45dbx_mem_check_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void at45dbx_mem_check_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_at45dbx_mem_check_CALL_INSTANCE));
  CMOCK_at45dbx_mem_check_CALL_INSTANCE* cmock_call_instance = (CMOCK_at45dbx_mem_check_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.at45dbx_mem_check_CallInstance = CMock_Guts_MemChain(Mock.at45dbx_mem_check_CallInstance, cmock_guts_index);
  Mock.at45dbx_mem_check_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.at45dbx_mem_check_IgnoreBool = (int)1;
}

void at45dbx_mem_check_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_at45dbx_mem_check_CALL_INSTANCE));
  CMOCK_at45dbx_mem_check_CALL_INSTANCE* cmock_call_instance = (CMOCK_at45dbx_mem_check_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.at45dbx_mem_check_CallInstance = CMock_Guts_MemChain(Mock.at45dbx_mem_check_CallInstance, cmock_guts_index);
  Mock.at45dbx_mem_check_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  memcpy(&cmock_call_instance->ReturnVal, &cmock_to_return, sizeof(_Bool));
  UNITY_CLR_DETAILS();
}

void at45dbx_mem_check_StubWithCallback(CMOCK_at45dbx_mem_check_CALLBACK Callback)
{
  Mock.at45dbx_mem_check_IgnoreBool = (int)0;
  Mock.at45dbx_mem_check_CallbackFunctionPointer = Callback;
}

