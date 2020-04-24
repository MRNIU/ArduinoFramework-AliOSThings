/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_eeprom.h>

void setup() {
  return;
}

void loop() {
    printf("Test Begin !\n");

    arduino_exp_eeprom_clear();
    arduino_exp_eeprom_read();
    arduino_exp_eeprom_write();
    arduino_exp_eeprom_update();
    eeprom_crc();
    arduino_exp_eeprom_crc();
    arduino_exp_eeprom_put();
    arduino_exp_eeprom_get();
    arduino_exp_eeprom_iterations();
    
    printf("Test End !\n");
    return;
}