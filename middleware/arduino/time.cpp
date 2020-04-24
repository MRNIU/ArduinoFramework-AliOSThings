/*
 * Copyright (C) 2019 MRNIU
 */

#include <include/arduino.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stddef.h>
#include <stdio.h>
#include <aos/kernel.h>
#include <aos/hal/gpio.h>

long long millis(void);
long long micros(void);
void delay(int ms);
void delayMicroseconds(long us);

/**
 * Get current time in ms.
 * 
 * @return	ms
 */
long long millis(void)
{
    return aos_now_ms();
}

/**
 * Get current time in us.
 * 
 * @return	us
 */
long long micros(void)
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
void delay(int ms)
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
void delayMicroseconds(long us)
{
    return;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
