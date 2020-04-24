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

void arduino_exp_time_millis(void)
{
    unsigned long time;
    
    printf("millis Time: ");
    time = millis();

    printf("%lu\n", time);
    delay(1000);

    return;
}