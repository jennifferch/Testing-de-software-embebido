#ifndef _AT45DBX_H_
#define _AT45DBX_H_

#include <stdbool.h>

bool at45dbx_mem_check();
bool at45dbx_init(int spiOptions,int pba_hz);
#endif /* #ifndef _AT45DBX_H_ */
