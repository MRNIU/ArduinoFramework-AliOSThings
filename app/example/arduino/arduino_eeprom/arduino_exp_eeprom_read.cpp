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

void arduino_exp_eeprom_read(void)
{
    uint32_t address = 0;
    byte value;
    value = EEPROM.read(address);

    printf("%lu", address);
    printf("\t");
    printf("%d\n", value);
    printf("\n");

    address = address + 1;
    if (address == EEPROM.length()) {
        address = 0;
    }
    
    delay(500);

    return;
}
