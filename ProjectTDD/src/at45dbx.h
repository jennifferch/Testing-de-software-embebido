#ifndef _AT45DBX_H_
#define _AT45DBX_H_

#include <stdbool.h>
#include <stdint.h>

#define AT45DBX_1MB             20
#define AT45DBX_2MB             21
#define AT45DBX_4MB             22
#define AT45DBX_8MB             23

#define AT45DBX_SECTOR_BITS     			8		  
#define AT45DBX_SECTOR_SIZE     (1 << AT45DBX_SECTOR_BITS)

bool at45dbx_mem_check();
bool at45dbx_init(int spiOptions,int pba_hz);
bool at45dbx_write_open(uint32_t  sector);
bool at45dbx_write_byte(uint8_t b);
bool at45dbx_write_close(void);
bool at45dbx_read_open(uint32_t sector);
uint8_t at45dbx_read_byte(void);
bool at45dbx_read_close(void);
#endif /* #ifndef _AT45DBX_H_ */
