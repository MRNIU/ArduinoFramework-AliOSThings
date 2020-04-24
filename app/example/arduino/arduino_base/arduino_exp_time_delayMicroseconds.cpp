/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_time_delayMicroseconds(void)
{
    pinMode(HAL_GPIO_55,OUTPUT);
    digitalWrite(HAL_GPIO_55, HIGH);

    delayMicroseconds(50);
    digitalWrite(HAL_GPIO_55, LOW);
    delayMicroseconds(50);
    
    return;
}