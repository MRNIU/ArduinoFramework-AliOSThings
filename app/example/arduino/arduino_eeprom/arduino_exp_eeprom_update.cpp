/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_eeprom.h>

void arduino_exp_eeprom_update(void)
{
    uint32_t address = 0;
    // int val = analogRead(0) / 4;
    int val = 2333;
    EEPROM.update(address, val);
    address = address + 1;
    if (address == EEPROM.length()) {
        address = 0;
    }
    delay(100);

    return;
}