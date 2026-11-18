This is a demo of interfacing STM32F446RE (NUCLEO board) with generic external audio codec via I2S for real time audio processing.

There are 2 bare-metal  projects, generated using STMCUBEMX: 
1. Real_time_audio__DMA for transmitting and receiving I2S data via DMA in circular mode
2. Real_time_audio__INT for transmitting and receiving I2S data via I2S interrupts.

Only pass-through with level indicator through LED, has been implemented, showcasing data acquisition from/to codec ,so the user can add his/her own processing routines using biquads, delay lines, dynamic processing etc.

* There is a codec hardware-abstraction-layer (HAL) consisting of codec_hal module, where any codec specific driver can fit, producing a  CodecInterface_t function table, which the user can use in application level (main.c).This way, the user can switch to a different codec by a single pointer assignment gaining portability.

* It is assumed that I2C is the control protocol for reading/writing codec registers from STM32F446RE-host, so in platform_interface module all basic I2C  single/block read/write functions are implemented using STM32 HAL  which should be used by codec_hal.c. 

