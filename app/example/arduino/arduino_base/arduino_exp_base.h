/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_EXP_BASE_H
#define ARDUINO_EXP_BASE_H

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#include <aos/hal/gpio.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <../middleware/arduino/api/ArduinoAPI.h>

#define LED_1 22
#define LED_2 63
#define HAL_GPIO_55 55
#define PORT_ADC1 1

void arduino_exp_dig_read(void);
void arduino_exp_dig_write(void);
void arduino_exp_dig_pinmode(void);

void arduino_exp_ana_read(void);
void arduino_exp_ana_write(void);

void arduino_exp_time_millis(void);
void arduino_exp_time_micros(void);
void arduino_exp_time_delay(void);
void arduino_exp_time_delayMicroseconds(void);

#endif /* ARDUINO_EXP_BASE_H */