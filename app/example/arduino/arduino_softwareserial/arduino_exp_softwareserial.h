
/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_EXP_SOFTWARESERIAL_H
#define ARDUINO_EXP_SOFTWARESERIAL_H

#include <../middleware/arduino/api/ArduinoAPI.h>
#include <../middleware/arduino/include/softwareserial.h>

void test(void);
void arduino_exp_ss_SoftwareSerial(void);
void arduino_exp_ss_available(void);
void arduino_exp_ss_begin(void);
void arduino_exp_ss_isListening(void);
void arduino_exp_ss_overflow(void);
void arduino_exp_ss_peek(void);
void arduino_exp_ss_read(void);
void arduino_exp_ss_write(void);
void arduino_exp_ss_listen(void);

#endif /* ARDUINO_EXP_SOFTWARESERIAL_H */