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

#include <api/ArduinoAPI.h>

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
