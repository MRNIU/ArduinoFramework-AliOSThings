/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <aos/kernel.h>
#include "st7789.h" /* LCD */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_lcd.h>

void setup() {
  return;
}

void loop() {
    printf("Test Begin !\n");

    // test();

    LiquidCrystal lcd;

    lcd.init();

    lcd.begin();

    // lcd.clear();

    lcd.write(1, 2, 0xF1);

    return;
}