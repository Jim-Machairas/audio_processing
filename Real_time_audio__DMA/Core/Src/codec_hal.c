#include <codec_hal.h>
#include <codec_registers.h>
#include <platform_interface.h>

/* Codec Driver public API implementation. */
int codec_drv_init(codec_dev_id dev, bool is_cold_start, const codec_pcfg_t *cfg)
{
	return 0;
}

int codec_drv_set_frame_len(codec_dev_id dev, uint16_t len)
{
	return 0;

}

int codec_drv_pll_init(codec_dev_id dev, bool master_mode, uint32_t in_rate, uint32_t out_rate, void * p_hw_cfg)
{
	return 0;

}

int codec_drv_set_sample_rate(codec_dev_id dev, uint32_t rate, void * p_hw_cfg)
{
	return 0;

}

int codec_drv_set_tdm_slots(codec_dev_id dev, uint16_t frame_len, uint8_t slot_width, uint8_t slot_cnt, void * p_hw_cfg)
{
	return 0;

}


const CodecInterface_t codec_driver =
{
	.codec_init = codec_drv_init,
	.set_codec_frame_len = codec_drv_set_frame_len,
	.codec_pll_init = codec_drv_pll_init,
	.codec_set_sample_rate = codec_drv_set_sample_rate,
    .codec_set_tdm_slots = codec_drv_set_tdm_slots,
};

