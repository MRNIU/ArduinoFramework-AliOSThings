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

void arduino_exp_ana_read(void)
{
    int val = 0;

    val = analogRead(PORT_ADC1);
    printf("val = %d\n", val);

    return;
}
