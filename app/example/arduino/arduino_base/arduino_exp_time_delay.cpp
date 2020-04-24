/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_time_delay(void)
{
    pinMode(LED_1,OUTPUT);

    digitalWrite(LED_1, HIGH);
    delay(1000);
    digitalWrite(LED_1, LOW);
    delay(1000);

    return;
}