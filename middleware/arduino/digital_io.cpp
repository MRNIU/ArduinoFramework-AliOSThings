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

#include <include/arduino.h>

static ListEntry * gpio_list = 0;

static gpio_config_t type_switch(uint8_t config);
int port_equal(void *vlocation1, void *vlocation2);

static gpio_config_t type_switch(uint8_t config)
{
    if(config == OUTPUT)
        return OUTPUT_PUSH_PULL;
    else if(config == INPUT)
        return INPUT_PULL_DOWN;
    return INPUT_PULL_UP;
}

int port_equal(void *vlocation1, void *vlocation2)
{
	gpio_dev_t *location1;
	gpio_dev_t *location2;

	location1 = (gpio_dev_t *) vlocation1;
	location2 = (gpio_dev_t *) vlocation2;

	return location1->port == location2->port;
}

/**
 * set pin mode
 *
 * @param[in]  pin   the pin number
 * @param[in]  config   INPUT or OUTPUT
 *
 * @return     void
 */
void pinMode(uint8_t pin, uint8_t config)
{
    gpio_dev_t * res = (gpio_dev_t *)list_find_data(gpio_list, port_equal, &pin);
    // pin not in gpio_list
    if(res == NULL) {
        gpio_dev_t * gpio_pin = (gpio_dev_t *)malloc(sizeof(gpio_dev_t));
        gpio_pin->port = pin;
        gpio_pin->config = type_switch(config);
        list_append(&gpio_list, gpio_pin);
    }
    // else update pin mode
    else {
        res->port = pin;
        res->config = type_switch(config);
    }

    return;
}

/**
 * write a digital pin
 *
 * @param[in]  pin  the pin which should be write
 * @param[in]  val   the value which should be write
 *
 * @return     void
 */
void digitalWrite(uint8_t pin, uint8_t val){
    gpio_dev_t * res = (gpio_dev_t *)list_find_data(gpio_list, port_equal, &pin);
    if(res == NULL) {
        printf("Error: pin not init!\n");
    }
    // else update pin mode
    else {
        printf("1\n");
        if(val == HIGH) {
            printf("2\n");
            if(hal_gpio_output_high(res))
                printf("hal_gpio_output_high error!\n");
            return;
        }
        else if(val == LOW) {
            printf("3\n");
            if(hal_gpio_output_low(res))
                printf("hal_gpio_output_low error!\n");
            return;
        }
    }
    return;
}

/**
 * Read a digital pin
 *
 * @param[in]  pin  the pin which should be read
 * @return     the value from gpio pin
 */
int digitalRead(uint8_t pin)
{
    uint32_t val;
    gpio_dev_t * res = (gpio_dev_t *)list_find_data(gpio_list, port_equal, &pin);
    if(res == NULL) {
        printf("Error: pin not init!\n");
        return -1;
    }
    else {
        if(hal_gpio_input_get(res, &val))
            printf("hal_gpio_input_get error!\n");
        return val;
    }
}
