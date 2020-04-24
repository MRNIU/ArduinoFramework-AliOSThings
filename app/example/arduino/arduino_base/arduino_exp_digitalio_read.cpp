/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_dig_read(void)
{
    int val = 0;

    pinMode(LED_2, OUTPUT);
    pinMode(HAL_GPIO_55, INPUT);

    val = digitalRead(HAL_GPIO_55);
    digitalWrite(LED_2, val);
    
    return;
}
