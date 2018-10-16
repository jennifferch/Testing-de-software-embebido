













typedef enum

{

  SPI_ERROR = -1,

  SPI_OK = 0,

  SPI_ERROR_TIMEOUT = 1,

  SPI_ERROR_ARGUMENT,

  SPI_ERROR_OVERRUN,

  SPI_ERROR_MODE_FAULT,

  SPI_ERROR_OVERRUN_AND_MODE_FAULT

} spi_status_t;





typedef struct

{



  unsigned char reg;





  unsigned int baudrate;





  unsigned char bits;





  unsigned char spck_delay;





  unsigned char trans_delay;





  unsigned char stay_act;





  unsigned char spi_mode;









  unsigned char modfdis;

} spi_options_t;



void spi_selectionMode(int spi,

                                      unsigned char variable_ps,

                                      unsigned char pcs_decode,

                                      unsigned char delay);



void spi_enable(int spi);
