/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_dig_pinmode(void)
{
    pinMode(LED_2, OUTPUT);

    while(1) {
        digitalWrite(LED_2, HIGH);
        delay(1000);
        digitalWrite(LED_2, LOW);
        delay(1000);
    }
    
    return;
}