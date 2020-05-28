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

#include <api/ArduinoAPI.h>

void detachInterrupt(pin_size_t interruptNumber)
{
    hal_interpt_umask(interruptNumber);
    return;
}
