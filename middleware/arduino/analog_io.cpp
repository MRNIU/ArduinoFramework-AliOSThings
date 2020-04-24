/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */ 

#include <stddef.h>
#include <stdio.h>
#include <aos/kernel.h>
#include <aos/hal/gpio.h>
#include <aos/hal/adc.h>
#include <aos/hal/dac.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#include <include/arduino.h>

#define DAC_CHANNEL_ONE 1

// hal_dac_ for developerkit are not applicable
/**
 * read analog pin
 *
 * @param[in]  pin  the pin which should be read
 * 
 * @return     the data being read
 */
int analogRead(uint8_t pin)
{
    int ret = 0;
    adc_dev_t adc_dev;
 
    adc_dev.port = pin;
    adc_dev.config.sampling_cycle = 100;
    adc_dev.priv = NULL;

    if(hal_adc_init(&adc_dev) != 0)
        printf("hal_adc_init error!\n");
    
    if(hal_adc_value_get(&adc_dev, &ret, HAL_WAIT_FOREVER))
        printf("hal_adc_value_get error!\n");
    hal_adc_finalize(&adc_dev);
    return ret;
}

/**
 * write analog pin
 *
 * @param[in]  pin  the pin which should be write
 * @param[in]  val   the value which should be write
 * 
 * @return     void
 */
void analogWrite(uint8_t pin, int val)
{
    dac_dev_t dac_dev;
 
    dac_dev.port = pin;
    dac_dev.priv = NULL;
    if(hal_dac_init(&dac_dev))
        printf("hal_dac_init error!\n");

    if(hal_dac_init(&dac_dev))
        printf("dac_dev init error !\n");

    if(hal_dac_set_value(&dac_dev, DAC_CHANNEL_ONE, val))
        printf("dac_dev set value error !\n");

    hal_dac_finalize(&dac_dev);
    return;   
}
