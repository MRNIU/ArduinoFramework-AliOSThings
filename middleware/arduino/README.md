
## Contents

```shell
├── analog_io.cpp
├── aos.mk
├── digital_io.cpp
├── include
│   ├── arduino.h
│   ├── character.h
│   ├── eeprom.h
│   ├── sd.h
│   └── serial.h
├── interrupt.cpp
├── math.cpp
├── sd.cpp
├── serial.cpp
└── time.cpp
```

## Introduction

`analog_io.cpp` is Arduino analog I/O function definition;
`digital_io.cpp` is Arduino digital I/O function definition;
`include/sd.h` is Arduino SD library;
`include/eeprom.h` is Arduino EEPROM library;
`include/arduino.h` is Arduino default header file;
`include/character.h` is Arduino character header file;
`include/serial.h` is Arduino serial header file;
`interrupt.cpp` is Arduino interrupt function definition;
`math.cpp` is Arduino math function definition;
`sd.cpp` is Arduino SD library definition;
`serial.cpp` is Arduino serial library definition;
`time.cpp` is Arduino time function definition;


## Different from Arduino

    - digital_io
        - `pinMode(uint8_t pin, uint8_t mode)`
            new: `pinMode(gpio_dev_t* gpio, uint8_t pin, arduino_pins_congig_t config)`
            `gpio`: a new gpio structure
            `pin`: pin number, which pin should be set

        - `digitalRead(uint8_t pin)` and `digitalWrite(uint8_t pin, uint8_t val)`
            `pin` -> `gpio_dev_t` structure

    - analog_io
        `pin` -> `gpio_dev_t` structure
        NOTES: 
            `gpio.port`: you can only use specified values in `hal_adc_xxx.h` or `hal_dac_xxx.h`
    - Wire
        `requestFrom` parameter `sendStop` not allow

    - wifi
        `setDNS(IPAddress dns_server1, IPAddress dns_server2)` not allow