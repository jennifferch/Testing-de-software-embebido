/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_AT45DBX_H
#define _MOCK_AT45DBX_H

#include "at45dbx.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_at45dbx_Init(void);
void mock_at45dbx_Destroy(void);
void mock_at45dbx_Verify(void);




#define at45dbx_mem_check_IgnoreAndReturn(cmock_retval) at45dbx_mem_check_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void at45dbx_mem_check_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
#define at45dbx_mem_check_ExpectAndReturn(cmock_retval) at45dbx_mem_check_CMockExpectAndReturn(__LINE__, cmock_retval)
void at45dbx_mem_check_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
typedef _Bool (* CMOCK_at45dbx_mem_check_CALLBACK)(int cmock_num_calls);
void at45dbx_mem_check_StubWithCallback(CMOCK_at45dbx_mem_check_CALLBACK Callback);
#define at45dbx_init_IgnoreAndReturn(cmock_retval) at45dbx_init_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void at45dbx_init_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
#define at45dbx_init_ExpectAndReturn(spiOptions, pba_hz, cmock_retval) at45dbx_init_CMockExpectAndReturn(__LINE__, spiOptions, pba_hz, cmock_retval)
void at45dbx_init_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int spiOptions, int pba_hz, _Bool cmock_to_return);
typedef _Bool (* CMOCK_at45dbx_init_CALLBACK)(int spiOptions, int pba_hz, int cmock_num_calls);
void at45dbx_init_StubWithCallback(CMOCK_at45dbx_init_CALLBACK Callback);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
