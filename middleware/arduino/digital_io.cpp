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

#include <api/ArduinoAPI.h>
#include <include/linkedlist.h>

static ListEntry * gpio_list = 0;

static gpio_config_t type_switch(PinMode pinMode);
int port_equal(void *vlocation1, void *vlocation2);

static gpio_config_t type_switch(PinMode pinMode)
{
    if(pinMode == OUTPUT)
        return OUTPUT_PUSH_PULL;
    else if(pinMode == INPUT)
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
void pinMode(pin_size_t pinNumber, PinMode pinMode)
{
    gpio_dev_t * res = (gpio_dev_t *)list_find_data(gpio_list, port_equal, &pinNumber);
    // pin not in gpio_list
    if(res == NULL) {
        gpio_dev_t * gpio_pin = (gpio_dev_t *)malloc(sizeof(gpio_dev_t));
        gpio_pin->port = pinNumber;
        gpio_pin->config = type_switch(pinMode);
        list_append(&gpio_list, gpio_pin);
    }
    // else update pin mode
    else {
        res->port = pinNumber;
        res->config = type_switch(pinMode);
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
void digitalWrite(pin_size_t pinNumber, PinStatus status) {
    gpio_dev_t * res = (gpio_dev_t *)list_find_data(gpio_list, port_equal, &pinNumber);
    if(res == NULL) {
        printf("Error: pin not init!\n");
    }
    // else update pin mode
    else {
        printf("1\n");
        if(status == HIGH) {
            printf("2\n");
            if(hal_gpio_output_high(res))
                printf("hal_gpio_output_high error!\n");
            return;
        }
        else if(status == LOW) {
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
PinStatus digitalRead(pin_size_t pinNumber)
{
    uint32_t val;
    gpio_dev_t * res = (gpio_dev_t *)list_find_data(gpio_list, port_equal, &pinNumber);
    if(res == NULL) {
        printf("Error: pin not init!\n");
        return LOW;
    }
    else {
        if(hal_gpio_input_get(res, &val))
            printf("hal_gpio_input_get error!\n");
        return (val == 0 ? LOW : HIGH);
    }
}
