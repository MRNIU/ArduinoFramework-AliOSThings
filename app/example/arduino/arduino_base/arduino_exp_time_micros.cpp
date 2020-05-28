/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_base.h>

void arduino_exp_time_micros(void)
{
    unsigned long time;
    
    print("micros Time: ");
    time = micros();

    print("%lu\n", time);
    delay(1000);

    return;
}