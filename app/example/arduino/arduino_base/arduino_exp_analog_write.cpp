/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_base.h>

void arduino_exp_ana_write(void)
{
    int val = 0;

    pinMode(LED_1, OUTPUT);

    val = analogRead(PORT_ADC1);
    analogWrite(LED_1, val / 4);

    return;
}

