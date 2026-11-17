#ifndef __PLATFORM_INTERFACE_
#define __PLATFORM_INTERFACE_

#include <codec_registers.h>
#include "stm32f4xx_hal.h"

#define dbg_err(fmt, ...)	do { } while (0)
#define RESPONSE_TIMEOUT 10

/* Codec Instances. */
typedef enum {
	CODEC_DEV0 = 0,
	CODEC_DEV1,
	CODEC_MAX_DEVS,
}codec_dev_id;

/* Slave device address for I2C found on datasheet. */
#define CODEC_DEV_ADDR 0x1A

/*
 * Host Specific i2C APIs to be used by codec driver.
 */
uint8_t plat_i2c_reg_read(const codec_dev_id dev, uint16_t reg, uint8_t *val);
uint8_t plat_i2c_blockreg_read(const codec_dev_id dev, uint16_t reg, uint8_t *buf,
		uint16_t len);
uint8_t plat_i2c_reg_write(const codec_dev_id dev, uint16_t reg, uint8_t val);
uint8_t plat_i2c_blockreg_write(const codec_dev_id dev, uint16_t reg,
			    const uint8_t *buf, uint16_t len);

#endif /* __PLATFORM_INTERFACE_ */
