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

#include <arduino_exp_base.h>

void arduino_exp_time_micros(void)
{
    unsigned long time;
    
    printf("micros Time: ");
    time = micros();

    printf("%lu\n", time);
    delay(1000);

    return;
}