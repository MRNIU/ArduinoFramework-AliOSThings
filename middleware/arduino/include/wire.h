/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_WIRE_H
#define ARDUINO_WIRE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stddef.h>
#include <aos/hal/i2c.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#define BUFFER_LENGTH 32

#define I2C1_PORT_NUM  1
#define I2C_TX_TIMEOUT 10
#define I2C_RX_TIMEOUT 10

#define I2C_DEV_ADDR       0x30f

class TwoWire
{
private:
    i2c_dev_t i2cdev;
    
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t* inBytes, int numBytes);
public:
    TwoWire();
    void begin();
    void begin(uint8_t address);
    void begin(int address);
    void end();
    void setClock(uint32_t clock);
    void beginTransmission(uint8_t address);
    void beginTransmission(int address);
    uint8_t endTransmission(void);
    uint8_t requestFrom(uint8_t address, uint8_t quantity);
	uint8_t requestFrom(uint8_t address, uint8_t quantity, uint32_t iaddress, uint8_t isize);
    uint8_t requestFrom(int address, int quantity);
    size_t write(uint8_t data);
    size_t write(const uint8_t *data, size_t quantity);
    int available(void);
    int read(void);
    void onReceive(void (*)(int));
    void onRequest(void (*)(void));

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
};

extern TwoWire Wire;

#endif /* ARDUINO_WIRE_H */
