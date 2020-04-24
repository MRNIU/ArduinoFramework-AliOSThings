/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_eeprom.h>

void arduino_exp_eeprom_write(void)
{
    uint32_t addr = 0;
    // int val = analogRead(0) / 4;
    uint32_t val = 666;
    
    EEPROM.write(addr, val);
    addr = addr+1;
    EEPROM.write(addr, val);
    if (addr == EEPROM.length()) {
        addr = 0;
    }
    delay(500);

    return;
}