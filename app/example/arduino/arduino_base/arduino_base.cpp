/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_base.h>

void setup() {
  return;
}

void loop() {
    printf("Test Begin !\n");

    arduino_exp_dig_read();
    arduino_exp_dig_write();
    arduino_exp_dig_pinmode();

    arduino_exp_ana_read();
    // arduino_exp_ana_write();

    arduino_exp_time_millis();
    arduino_exp_time_micros();
    arduino_exp_time_delay();
    arduino_exp_time_delayMicroseconds();

    print("Test End !\n");

    return;
}