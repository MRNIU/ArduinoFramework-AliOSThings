/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <aos/hal/interpt.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <include/arduino.h>

void attachInterrupt(uint32_t, void (*)(void), int mode);
void detachInterrupt(uint32_t);

void attachInterrupt(uint32_t vec, void (*tmp)(void), int mode)
{
    return;
}

void detachInterrupt(uint32_t vec)
{
    hal_interpt_umask(vec);
    return;
}
