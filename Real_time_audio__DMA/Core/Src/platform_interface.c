
#include <platform_interface.h>
#include "main.h"

/* In the following APIs, the blocking version of STM32's i2C driver was used
 * for transmit/receive. Interrupt or DMA versions can be used as well depending on application. */


uint8_t plat_i2c_reg_read(const codec_dev_id dev, uint16_t reg, uint8_t *val)
{
	uint8_t I2C_Data[REG_ADDR_LENGTH];
	uint8_t result;

	/* First transmit 16-bit reg address */

    I2C_Data[0] = (uint8_t) ((reg>>8) & 0xFF);  // RegAddr High byte
    I2C_Data[1] = (uint8_t) (reg&0xFF);  // RegAddr Low byte
    result = HAL_I2C_Master_Transmit(&hi2c1, (CODEC_DEV_ADDR << 1), I2C_Data, REG_ADDR_LENGTH, RESPONSE_TIMEOUT);
    if (result != HAL_OK)
    {
    	return result;
    }

    /* Then request reg 8 bit value read  */
    result = HAL_I2C_Master_Receive(&hi2c1, (CODEC_DEV_ADDR << 1), val, REG_VAL_LENGTH, RESPONSE_TIMEOUT);

	return result;
}

uint8_t plat_i2c_blockreg_read(const codec_dev_id dev, uint16_t reg, uint8_t *buf,
			   uint16_t len)
{
    uint8_t I2C_Data[REG_ADDR_LENGTH];
    uint8_t result;

	for (uint16_t i = 0;i < len; i++)
	{
	    /* First transmit 16-bit reg address */
		I2C_Data[0] = (uint8_t) (((reg + i)>>8) & 0xFF);  // RegAddr High byte
	    I2C_Data[1] = (uint8_t) (((reg + i) & 0xFF));  // RegAddr Low byte

	    result = HAL_I2C_Master_Transmit(&hi2c1, (CODEC_DEV_ADDR << 1), I2C_Data, REG_ADDR_LENGTH, RESPONSE_TIMEOUT);
	    if (result != HAL_OK)
	    {
	    	return result;
	    }
	    /* Then request reg 8 bit value read  */
	    result = HAL_I2C_Master_Receive(&hi2c1,(CODEC_DEV_ADDR << 1), buf + i, REG_VAL_LENGTH, RESPONSE_TIMEOUT);
	    if (result != HAL_OK)
	    {
	    	return result;
	    }
	}

	return result;
}

uint8_t plat_i2c_reg_write(const codec_dev_id dev, uint16_t reg, uint8_t val)
{

    uint8_t I2C_Data[REG_ADDR_LENGTH + REG_VAL_LENGTH];

    I2C_Data[0] = (uint8_t) ((reg>>8) & 0xFF);  // RegAddr High byte
    I2C_Data[1] = (uint8_t) ((reg & 0xFF));  // RegAddr Low byte
    I2C_Data[2] = (uint8_t) (val & 0xFF);    // RegValue
    uint8_t result = HAL_I2C_Master_Transmit(&hi2c1, (CODEC_DEV_ADDR << 1), I2C_Data, REG_ADDR_LENGTH + REG_VAL_LENGTH, RESPONSE_TIMEOUT);

	return result;
}

uint8_t plat_i2c_blockreg_write(const codec_dev_id dev, uint16_t reg,
			    const uint8_t *buf, uint16_t len)
{
    uint8_t I2C_Data[REG_ADDR_LENGTH + REG_VAL_LENGTH];
    uint8_t data_buf[len];
    uint8_t result;

    memcpy(data_buf, buf, len);


	for (uint16_t i = 0;i < len; i++)
	{
	    I2C_Data[0] = (uint8_t) (((reg + i) >> 8) & 0xFF);  // RegAddr High byte
	    I2C_Data[1] = (uint8_t) (((reg + i) & 0xFF));  // RegAddr Low byte
	    I2C_Data[2] = (uint8_t) (data_buf[i] & 0xFF);    // RegValue

	    result = HAL_I2C_Master_Transmit(&hi2c1, (CODEC_DEV_ADDR << 1), I2C_Data, REG_ADDR_LENGTH + REG_VAL_LENGTH, RESPONSE_TIMEOUT);
	    if (result != HAL_OK)
	    {
	    	return result;
	    }
	}

	return result;
}
