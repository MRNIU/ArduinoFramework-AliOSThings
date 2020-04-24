/*
 * Copyright (C) 2019 MRNIU
 */

#include <arduino_exp_eeprom.h>

void arduino_exp_eeprom_iterations(void)
{
    for (uint32_t index = 0 ; index < EEPROM.length() ; index++) {
        EEPROM[index] += 1;
    }
    uint32_t index = 0;
    while (index < EEPROM.length()) {
        EEPROM[ index ] += 1;
        index++;
    }

    uint32_t idx = 0;
    do {
        EEPROM[idx] += 1;
        idx++;
    } while (idx < EEPROM.length());
    
    return;
}

