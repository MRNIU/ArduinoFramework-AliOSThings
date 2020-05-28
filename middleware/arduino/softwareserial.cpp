/*
 * Copyright (C) 2019 MRNIU
 */

#include <include/softwareserial.h>

uint8_t SoftwareSerial::readbuf[BUFSIZE]; 
volatile uint8_t SoftwareSerial::buffer_head    = 0;
volatile uint8_t SoftwareSerial::buffer_tail    = 0;
SoftwareSerial*  SoftwareSerial::active_object  = NULL;

SoftwareSerial::SoftwareSerial(uint8_t uart_port, bool inverse_logic)
{
    uart.port = uart_port;
    uart.config.data_width   = DATA_WIDTH_8BIT;
    uart.config.parity       = NO_PARITY;
    uart.config.stop_bits    = STOP_BITS_1;
    uart.config.flow_control = FLOW_CONTROL_DISABLED;
    uart.config.mode         = MODE_TX_RX;
    this->buffer_overflow    = false;
    this->inverse_logic      = inverse_logic;
    return;
}

SoftwareSerial::~SoftwareSerial()
{
    end();
    return;
}

void SoftwareSerial::begin(unsigned long baudrate)
{
    this->uart.config.baud_rate    = baudrate;
    
    int ret = -1;
    ret = hal_uart_init(&this->uart); 
    if (ret != 0) {
        printf("uart init error !\n");
    }

    return;
}

bool SoftwareSerial::listen()
{
    if (active_object != this) {
        if (active_object)
            active_object->stopListening();
        active_object = this;
        return true;
    }
    return false;
}

void SoftwareSerial::end()
{
    this->stopListening();
    int ret = -1;
    ret = hal_uart_finalize(&this->uart);
    if (ret != 0) {
        printf("uart finalize error !\n");
    }
    return;
}

bool SoftwareSerial::isListening()
{
    return this == active_object;
}

bool SoftwareSerial::stopListening()
{
    if (active_object == this) {
        active_object = NULL;
        return true;
    }
    return false;
}

bool SoftwareSerial::overflow()
{
    bool ret = this->buffer_overflow; 
    if (ret) 
        this->buffer_overflow = false; 
    return ret; 
}

int SoftwareSerial::peek()
{
    if (!this->isListening())
        return -1;
    if (this->buffer_head == this->buffer_tail)
        return -1;

    return this->readbuf[this->buffer_head];
}

size_t SoftwareSerial::write(uint8_t byte)
{
    if (this->inverse_logic)
        byte = ~byte;

    int ret = -1;
    ret = hal_uart_send(&this->uart, &byte, sizeof(byte), HAL_WAIT_FOREVER);
    if (ret == 0) {
        printf("uart data send succeed !\n");
    }
    return 1;
}

size_t SoftwareSerial::write(std::string str)
{
    int ret = -1;
    ret = hal_uart_send(&this->uart, &str, sizeof(str), HAL_WAIT_FOREVER);
    if (ret == 0) {
        printf("uart data send succeed !\n");
    }
    return sizeof(str);
}

int SoftwareSerial::read(void)
{
    if (!this->isListening())
        return -1;

    if (this->buffer_head == this->buffer_tail)
        return -1;

    uint8_t data = this->readbuf[this->buffer_head];
    this->buffer_head = (this->buffer_head + 1) % BUFSIZE;
  
    return data;
}

int SoftwareSerial::available()
{
    if (!isListening())
        return 0;
    
    int res = 0;
    res = (this->buffer_tail + BUFSIZE - this->buffer_head) % BUFSIZE;
    
    return res;
}

void SoftwareSerial::flush()
{
    return;
}

SoftwareSerial::operator bool()
{
    return true;
}

inline void SoftwareSerial::handle_interrupt()
{
    if (active_object) {
        active_object->recv();
    }
    return;
}

void SoftwareSerial::recv(void)
{
    uint8_t data;
    uint32_t ret = 0;
    uint32_t recv_size;
    ret = hal_uart_recv(&this->uart, (void *)&data, sizeof(data), HAL_WAIT_FOREVER);
    if(ret){
        hal_uart_recv_II(&this->uart, (void *)&data, sizeof(data), &recv_size, HAL_WAIT_FOREVER);
    }

    if (this->inverse_logic)
        data = ~data;

    uint8_t next = (this->buffer_tail + 1) % BUFSIZE;
    if (next != this->buffer_head) {
        this->readbuf[this->buffer_tail] = data;
        this->buffer_tail = next;
    } else {
        this->buffer_overflow = true;
    }
    
    return;
}