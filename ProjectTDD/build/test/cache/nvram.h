









int nvram_init(void);

int nvram_read(uint32_t addr, void *data, uint32_t len);

int nvram_write(uint32_t addr, const void *data, uint32_t len);
