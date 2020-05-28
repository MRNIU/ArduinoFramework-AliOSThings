/*
 * Copyright (C) 2019 MRNIU
 */

#include <api/ArduinoAPI.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stddef.h>
#include <stdio.h>
#include <aos/kernel.h>
#include <api/ArduinoAPI.h>

/**
 * Get current time in ms.
 * 
 * @return	ms
 */
unsigned long millis(void)
{
    return aos_now_ms();
}

/**
 * Get current time in us.
 * 
 * @return	us
 */
unsigned long micros(void)
{
    return aos_now()/1000;
}

/**
 * sleep ms
 *
 * @param[in]  ms  sleep time in ms
 * 
 * @return     void
 */
void delay(unsigned long ms)
{
	aos_msleep(ms);
    return;
}

/**
 * sleep us
 * NOT AVAILABLE!!!
 * 
 * @param[in]  us  sleep time in us
 * 
 * @return     void
 */
void delayMicroseconds(unsigned int us)
{
    return;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
