/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_SOFTWARESERIAL_H
#define ARDUINO_SOFTWARESERIAL_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <aos/hal/uart.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <string>

#define BUFSIZE 64

class SoftwareSerial {
private:
    uart_dev_t uart;
    bool buffer_overflow;
    bool inverse_logic;
    static uint8_t readbuf[BUFSIZE];
    static volatile uint8_t buffer_tail;
    static volatile uint8_t buffer_head;
    static SoftwareSerial * active_object;
    inline void recv() __attribute__((__always_inline__));
public:
    SoftwareSerial(uint8_t uart_port, bool inverse_logic = false);
    ~SoftwareSerial();
    void begin(uint32_t speed);
    bool listen();
    void end();
    bool isListening();
    bool stopListening();
    bool overflow();
    int peek();
    size_t write(uint8_t byte);
    size_t write(std::string str);
    int read();
    int available();
    void flush();
    operator bool();
    
    static inline void handle_interrupt() __attribute__((__always_inline__));
};

#endif /* ARDUINO_SOFTWARESERIAL_H */
