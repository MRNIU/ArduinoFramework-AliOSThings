/*
 * Copyright (C) 2019 MRNIU
 */

#include <include/wire.h>
#include <stdio.h>

uint8_t TwoWire::rxBuffer[BUFFER_LENGTH];
uint8_t TwoWire::rxBufferIndex  = 0;
uint8_t TwoWire::rxBufferLength = 0;

uint8_t TwoWire::txAddress      = 0;
uint8_t TwoWire::txBuffer[BUFFER_LENGTH];
uint8_t TwoWire::txBufferIndex  = 0;
uint8_t TwoWire::txBufferLength = 0;

uint8_t TwoWire::transmitting   = 0;
void (*TwoWire::user_onRequest)(void);
void (*TwoWire::user_onReceive)(int);

TwoWire::TwoWire()
{
    return;
}

/**
 * Initiate the Wire library and join the I2C bus as a master.
 *
 * @return     void
 */
void TwoWire::begin()
{
    int ret = -1;

    this->i2cdev.port                 = I2C1_PORT_NUM;
    this->i2cdev.config.mode          = I2C_MODE_MASTER;
    this->i2cdev.config.freq          = 30000000;
    this->i2cdev.config.address_width = I2C_MEM_ADDR_SIZE_8BIT;
    this->i2cdev.config.dev_addr      = I2C_DEV_ADDR;

    ret = hal_i2c_init(&this->i2cdev);
    if(ret != 0)
        printf("i2c init error! %d\n", ret);

    return;
}

/**
 * Initiate the Wire library and join the I2C bus as a slave.
 *
 * @param[in]  address  the 7-bit slave address.
 * 
 * @return     void
 */
void TwoWire::begin(uint8_t address)
{
    int ret = -1;

    this->i2cdev.port                 = I2C1_PORT_NUM;
    this->i2cdev.config.mode          = I2C_MODE_SLAVE;
    this->i2cdev.config.freq          = 30000000;
    this->i2cdev.config.address_width = I2C_MEM_ADDR_SIZE_8BIT;
    this->i2cdev.config.dev_addr      = address;

    ret = hal_i2c_init(&this->i2cdev);
    if(ret != 0)
        printf("i2c init error! %d\n", ret);
    
    return;
}

void TwoWire::begin(int address)
{
    this->begin((uint8_t)address);
    return;
}

void TwoWire::end()
{
    int ret = -1;

    ret = hal_i2c_finalize(&this->i2cdev);
    if (ret != 0) {
        printf("i2c finalize error! %d\n", ret);
    }

    return;
}

/**
 * This function modifies the clock frequency for I2C communication.
 *
 * @param[in]  clock  the value (in Hertz) of desired communication clock
 * 
 * @return     void
 */
void TwoWire::setClock(uint32_t clock)
{
    this->i2cdev.config.freq = clock;
    return;
}

/**
 * Begin a transmission to the I2C slave device with the given address.
 *
 * @param[in]  address  the 7-bit address of the device to transmit to
 * 
 * @return     void
 */
void TwoWire::beginTransmission(uint8_t address)
{
    this->transmitting = 1;
    this->txAddress = address;
    this->txBufferIndex = 0;
    this->txBufferLength = 0;
    
    return;
}

void TwoWire::beginTransmission(int address)
{
    this->beginTransmission((uint8_t)address);
}

/**
 * Ends a transmission to a slave device that was begun by beginTransmission() 
 *  and transmits the bytes that were queued by write().
 * 
 * @return     byte, which indicates the status of the transmission
 */
uint8_t TwoWire::endTransmission(void)
{
    uint8_t res = 0;
    int ret = -1;

    ret = hal_i2c_master_send(&this->i2cdev, this->txAddress, &res, 1, I2C_TX_TIMEOUT);
    if (ret == 0) {
        printf("i2c data received succeed !\n");
    }

    this->txBufferIndex = 0;
    this->txBufferLength = 0;
    this->transmitting = 0;
    
    return res;
}

/**
 * Used by the master to request bytes from a slave device. 
 * The bytes may then be retrieved with the available() and read() functions.
 *
 * @param[in]  address  the 7-bit address of the device to request bytes from
 * @param[in]  quantity  the number of bytes to request
 * 
 * @return     the number of bytes returned from the slave device
 */
uint8_t TwoWire::requestFrom(int address, int quantity)
{
    return this->requestFrom((uint8_t)address, (uint8_t)quantity);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity)
{
    return this->requestFrom((uint8_t)address, (uint8_t)quantity, (uint32_t)0, (uint8_t)0);
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint32_t iaddress, uint8_t isize)
{
    if (isize > 0) {
        this->beginTransmission(address);

        if (isize > 3) {
            isize = 3;
        }
        while (isize-- > 0)
            write( (uint8_t)( iaddress >> (isize * 8) ) );
        this->endTransmission();
    }

    if(quantity > BUFFER_LENGTH) {
        quantity = BUFFER_LENGTH;
    }

    uint8_t read = 0;
    int ret = -1;

    i2c_dev_t i2cdev_slave;

    i2cdev_slave.port                 = I2C1_PORT_NUM;
    i2cdev_slave.config.mode          = I2C_MODE_SLAVE;
    i2cdev_slave.config.freq          = 30000000;
    i2cdev_slave.config.address_width = I2C_MEM_ADDR_SIZE_8BIT;
    i2cdev_slave.config.dev_addr      = address;

    ret = hal_i2c_init(&i2cdev_slave);
    if(ret != 0)
        printf("i2c init error! %d\n", ret);

    ret = hal_i2c_slave_recv(&i2cdev_slave, &read, sizeof(read), I2C_RX_TIMEOUT);
    if (ret == 0) {
        printf("i2c data received succeed !\n");
    }

    this->rxBufferIndex = 0;
    this->rxBufferLength = read;

    return read;
}

/**
 * Writes data from a slave device in response to a request from a master, 
 *  or queues bytes for transmission from a master to slave device 
 *  (in-between calls to beginTransmission() and endTransmission()).
 *
 * @param[in]  data  a value to send as a single byte
 * 
 * @return     the number of bytes written, though reading that number is optional
 */
size_t TwoWire::write(uint8_t data)
{
    if(this->transmitting) {
        if(this->txBufferLength >= BUFFER_LENGTH) {
            printf("error!\n");
            return 0;
        }
        
        this->txBuffer[this->txBufferIndex] = data;
        ++this->txBufferIndex;
        this->txBufferLength = this->txBufferIndex;
    } else {
        int ret = -1;

        ret = hal_i2c_slave_send(&this->i2cdev, &data, 1, I2C_TX_TIMEOUT);
        if (ret == 0) {
            printf("i2c data send succeed !\n");
        }
    }

    return 1;
}

/**
 * Writes data from a slave device in response to a request from a master, 
 *  or queues bytes for transmission from a master to slave device 
 *  (in-between calls to beginTransmission() and endTransmission()).
 *
 * @param[in]  data  an array of data to send as bytes
 * @param[in]  quantity  the number of bytes to transmit
 * 
 * @return     the number of bytes written, though reading that number is optional
 */
size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
    if(this->transmitting) {
        for(size_t i = 0; i < quantity; ++i) {
            write(data[i]);
        }
    } else {
        int ret = -1;
        ret = hal_i2c_slave_send(&this->i2cdev, data, quantity, I2C_TX_TIMEOUT);
        if (ret == 0) {
           printf("i2c data send succeed !\n");
        }
    }
    return quantity;
}

/**
 * Returns the number of bytes available for retrieval with read().
 *
 * @return     The number of bytes available for reading.
 */
int TwoWire::available(void)
{
    return this->rxBufferLength - this->rxBufferIndex;
}

/**
 * Reads a byte that was transmitted from a slave device to a master after a call 
 *  to requestFrom() or was transmitted from a master to a slave.
 *
 * @return     The next byte received
 */
int TwoWire::read(void)
{
    int value = -1;

    if(this->rxBufferIndex < this->rxBufferLength) {
        value = this->rxBuffer[this->rxBufferIndex];
        ++this->rxBufferIndex;
    }

    return value;
}

/**
 * Registers a function to be called when a slave device receives a transmission from a master.
 *
 * @param[in]  function  the function to be called when the slave receives data
 * 
 * @return     void
 */
void TwoWire::onReceive(void (*function)(int))
{
    user_onReceive = function;
    return;
}

/**
 * Register a function to be called when a master requests data from this slave device.
 *
 * @param[in]  function  the function to be called, takes no parameters and returns nothing
 * 
 * @return     void
 */
void TwoWire::onRequest(void (*function)(void))
{
    user_onRequest = function;
    return;
}

void TwoWire::onRequestService(void)
{
    if(!user_onRequest) {
        return;
    }
    txBufferIndex = 0;
    txBufferLength = 0;
    user_onRequest();
    return;
}

void TwoWire::onReceiveService(uint8_t* inBytes, int numBytes)
{
    if(!user_onReceive) {
        return;
    }
    if(rxBufferIndex < rxBufferLength) {
        return;
    }
    for(uint8_t i = 0; i < numBytes; ++i) {
        rxBuffer[i] = inBytes[i];
    }
    rxBufferIndex = 0;
    rxBufferLength = numBytes;
    user_onReceive(numBytes);
    return;
}

TwoWire Wire = TwoWire();
