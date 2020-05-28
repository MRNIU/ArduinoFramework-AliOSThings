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
    
    print("millis Time: ");
    time = millis();

    print("%lu\n", time);
    delay(1000);

    return;
}