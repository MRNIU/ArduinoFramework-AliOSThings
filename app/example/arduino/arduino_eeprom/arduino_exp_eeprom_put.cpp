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

void arduino_exp_eeprom_put(void)
{
    float f = 123.456f;
    uint32_t eeAddress = 0;

    EEPROM.put(eeAddress, f);

    printf("Written float data type!\n");

    MyObject customVar = {
        3.14f,
        65,
        "Working!"
    };
    eeAddress += sizeof(float);
    EEPROM.put(eeAddress, customVar);
    printf("Written custom data type! \n\nView the example sketch eeprom_get to see how you can retrieve the values!\n");
    return;
}