#include <codec_hal.h>
#include <codec_registers.h>
#include <platform_interface.h>

/* Codec Driver public API implementation. */
int codec_drv_init(codec_dev_id dev, bool is_cold_start, const codec_pcfg_t *cfg)
{
	/* Copy related codec driver content here. */


	/* Codec registers should be accessed via host-platform specific i2c read/write functions */
	uint8_t reset_reg_val;
	uint8_t result = plat_i2c_reg_read(CODEC_DEV0, RESET_REG, &reset_reg_val);

	/* Use driver defined error code return values */
	return result;

}

int codec_drv_set_frame_len(codec_dev_id dev, uint16_t len)
{
	/* Copy related codec driver content here. */

	/* Codec registers should be accessed via host-platform specific i2c read/write functions */
	uint8_t result = plat_i2c_reg_write(CODEC_DEV0, FRAME_REG, 0xFF);

	/* Use driver defined error code return values */
	return result;

}

int codec_drv_pll_init(codec_dev_id dev, bool master_mode, uint32_t in_rate, uint32_t out_rate, void * p_hw_cfg)
{
	/* Copy related codec driver content here. */

	/* Codec registers should be accessed via host-platform specific i2c read/write functions */
	return 0;

}

int codec_drv_set_sample_rate(codec_dev_id dev, uint32_t rate, void * p_hw_cfg)
{
	/* Copy related codec driver content here. */

	/* Codec registers should be accessed via host-platform specific i2c read/write functions */
	return 0;

}

int codec_drv_set_tdm_frmt(codec_dev_id dev, uint16_t frame_len, uint8_t slot_width, uint8_t slot_cnt, void * p_hw_cfg)
{
	/* Copy related codec driver content here. */

	/* Codec registers should be accessed via host-platform specific i2c read/write functions */
	return 0;

}


const CodecInterface_t codec_driver =
{
	.codec_init = codec_drv_init,
	.set_codec_frame_len = codec_drv_set_frame_len,
	.codec_pll_init = codec_drv_pll_init,
	.codec_set_sample_rate = codec_drv_set_sample_rate,
    .codec_set_tdm_frmt= codec_drv_set_tdm_frmt,
};

