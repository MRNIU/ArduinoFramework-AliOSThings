/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <aos/hal/gpio.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "aos/yloop.h"
#include <api/ArduinoAPI.h>

int application_start(int argc, char *argv[]){
    setup();
    loop();
    aos_loop_run();
    return 0;
}