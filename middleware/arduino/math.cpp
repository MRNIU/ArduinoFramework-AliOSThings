/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" { 
#endif /* __cplusplus */

#include <stdlib.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <include/arduino.h>

void randomSeed(unsigned long seed)
{
    if (seed != 0) {
        srandom(seed);
    }
}

long random(long howbig)
{
    if (howbig == 0) {
        return 0;
    }
    return random() % howbig;
}

long random(long howsmall, long howbig)
{
    if (howsmall >= howbig) {
        return howsmall;
    }
    long diff = howbig - howsmall;
    return random(diff) + howsmall;
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t makeWord(uint16_t w) 
{ 
    return w;
}

uint16_t makeWord(byte h, byte l) 
{ 
    return (h << 8) | l; 
}