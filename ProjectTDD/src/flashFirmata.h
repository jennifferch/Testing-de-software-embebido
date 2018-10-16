#ifndef _FLASHFIRMATA_H
#define _FLASHFIRMATA_H
#include <stdint.h>

#define SECTOR_SIZE AT45DBX_SECTOR_SIZE

int mem_check(void);
void led_init(void);
int flash_init(int spiOptions);
int fw_download_init(void);
int flash_write(uint32_t  addr, const uint8_t* buf, uint32_t len);
int flash_read(uint32_t addr, uint8_t* buf, uint32_t len);
#endif // _FLASHFIRMATA_H
