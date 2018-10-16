





_Bool 

    at45dbx_mem_check();



_Bool 

    at45dbx_init(int spiOptions,int pba_hz);



_Bool 

    at45dbx_write_open(uint32_t sector);



_Bool 

    at45dbx_write_byte(uint8_t b);



_Bool 

    at45dbx_write_close(void);



_Bool 

    at45dbx_read_open(uint32_t sector);

uint8_t at45dbx_read_byte(void);



_Bool 

    at45dbx_read_close(void);
