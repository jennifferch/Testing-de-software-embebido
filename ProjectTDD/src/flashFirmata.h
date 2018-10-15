#ifndef _FLASHFIRMATA_H
#define _FLASHFIRMATA_H

#define SECTOR_SIZE AT45DBX_SECTOR_SIZE

int mem_check(void);
void led_init(void);
void flash_init(void);

#endif // _FLASHFIRMATA_H
