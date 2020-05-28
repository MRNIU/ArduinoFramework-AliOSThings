/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_EXP_EEPROM_H
#define ARDUINO_EXP_EEPROM_H

#include <../middleware/arduino/api/ArduinoAPI.h>
#include <../middleware/arduino/include/eeprom.h>

#define LED_1 22

struct MyObject {
  float field1;
  byte field2;
  char name[10];
};

void arduino_exp_eeprom_clear(void);
void arduino_exp_eeprom_read(void);
void arduino_exp_eeprom_write(void);
void arduino_exp_eeprom_update(void);
unsigned long eeprom_crc(void);
void arduino_exp_eeprom_crc(void);
void arduino_exp_secondTest();
void arduino_exp_eeprom_get(void);
void arduino_exp_eeprom_put(void);
void arduino_exp_eeprom_iterations(void);

#endif /* ARDUINO_EXP_EEPROM_H */
