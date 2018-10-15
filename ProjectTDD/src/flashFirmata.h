#ifndef _FLASHFIRMATA_H
#define _FLASHFIRMATA_H

#define SECTOR_SIZE AT45DBX_SECTOR_SIZE

int mem_check(void);
void led_init(void);
int flash_init(int spiOptions);

#endif // _FLASHFIRMATA_H
