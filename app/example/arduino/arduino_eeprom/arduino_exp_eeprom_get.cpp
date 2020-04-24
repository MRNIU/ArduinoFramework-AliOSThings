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

void arduino_exp_secondTest() {
    uint32_t eeAddress = sizeof(float);
    MyObject customVar;
    EEPROM.get(eeAddress, customVar);

    printf("Read custom object from EEPROM: ");
    printf("%f\n", customVar.field1);
    printf("%d\n", customVar.field2);
    printf("%s\n", customVar.name);

    return;
}

void arduino_exp_eeprom_get(void) 
{
    float f = 0.00f;
    uint32_t eeAddress = 0;
    
    printf("Read float from EEPROM: ");
    EEPROM.get(eeAddress, f);
    
    printf("%3f\n", f);
    
    arduino_exp_secondTest();

    return;
}