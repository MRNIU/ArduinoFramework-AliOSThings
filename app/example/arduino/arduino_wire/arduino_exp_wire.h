/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_EXP_SOFTWARESERIAL_H
#define ARDUINO_EXP_SOFTWARESERIAL_H

#include <../middleware/arduino/include/arduino.h>
#include <../middleware/arduino/include/wire.h>

#define I2C_BUF_SIZE   10

void test(void);
void arduino_exp_wire_write(void);
void arduino_exp_wire_read(void);

#endif /* ARDUINO_EXP_SOFTWARESERIAL_H */