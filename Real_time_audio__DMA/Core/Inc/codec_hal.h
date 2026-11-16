#ifndef __CODEC_HAL_H
#define __CODEC_HAL_H

/* Contains all codec specific driver and an interface for portability. */
#include <stdbool.h>
#include <platform_interface.h>

typedef struct
{
	uint8_t input_ch_num;
	uint8_t output_ch_num;
	uint8_t input_gain_db;
	uint8_t output_gain_db;
}codec_pcfg_t;

typedef struct
{
    int (*codec_init) (codec_dev_id dev, bool is_cold_start, const codec_pcfg_t *cfg);
    int (*set_codec_frame_len) (codec_dev_id dev, uint16_t len);
    int (*codec_pll_init) (codec_dev_id dev, bool master_mode, uint32_t in_rate, uint32_t out_rate, void * p_hw_cfg);
    int (*codec_set_sample_rate) (codec_dev_id dev, uint32_t rate, void * p_hw_cfg);
    int (*codec_set_tdm_slots) (codec_dev_id dev, uint16_t frame_len, uint8_t slot_width, uint8_t slot_cnt, void * p_hw_cfg);
} CodecInterface_t;

extern const CodecInterface_t codec_driver;

/* Codec Driver pubic APIs */
int codec_drv_init(codec_dev_id dev, bool is_cold_start, const codec_pcfg_t *cfg);

int codec_drv_set_frame_len(codec_dev_id dev, uint16_t len);

int codec_drv_pll_init(codec_dev_id dev, bool master_mode, uint32_t in_rate, uint32_t out_rate, void * p_hw_cfg);

int codec_drv_set_sample_rate(codec_dev_id dev, uint32_t rate, void * p_hw_cfg);

int codec_drv_set_tdm_slots(codec_dev_id dev, uint16_t frame_len, uint8_t slot_width, uint8_t slot_cnt, void * p_hw_cfg);

#endif /* __CODEC_HAL_H */
