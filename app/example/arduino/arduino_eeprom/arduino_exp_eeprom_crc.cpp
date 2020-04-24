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

unsigned long eeprom_crc(void) 
{
    const unsigned long crc_table[16] = {
        0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
        0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
        0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
        0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
    };

    unsigned long crc = ~0L;

    for(uint32_t index = 0 ; index < EEPROM.length() ; ++index) {
        crc = crc_table[(crc ^ EEPROM[index]) & 0x0f] ^ (crc >> 4);
        crc = crc_table[(crc ^ (EEPROM[index] >> 4)) & 0x0f] ^ (crc >> 4);
        crc = ~crc;
    }
    return crc;
}

void arduino_exp_eeprom_crc(void)
{
    printf("EEPROM length: ");
    printf("%lu\n", EEPROM.length());
    printf("CRC32 of EEPROM data: 0x");
    printf("%x\n", (unsigned int)eeprom_crc());
    printf("\n\nDone!\n");

    return;
}
