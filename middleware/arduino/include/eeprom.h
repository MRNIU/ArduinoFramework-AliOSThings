/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_EEPROM_H
#define ARDUINO_EEPROM_H

#include <stdio.h>
#include <aos/hal/flash.h>

#define WRITE(idx, val, type) \
        hal_flash_write(HAL_PARTITION_PARAMETER_3, \
                        (uint32_t *)&idx, \
                        (void*)&val, \
                        (uint32_t)sizeof(type));

#define READ(idx, res, type) \
        hal_flash_read(HAL_PARTITION_PARAMETER_3, \
                        (uint32_t *)&idx, \
                        (void*)&res, \
                        (uint32_t)sizeof(type));

struct EERef{
    EERef(const uint32_t index) : index(index) {}
    
    uint8_t operator*() const
    {
        uint8_t res;
        READ(index, res, uint8_t);
        return res;
    }

    operator uint8_t() const           { return **this; }
    
    EERef &operator=(const EERef &ref) { return *this = *ref; }
    EERef &operator=(int8_t in)        { WRITE(index, in, uint8_t); return *this; }
    EERef &operator +=(uint8_t in)     { return *this = **this + in; }
    EERef &operator -=(uint8_t in)     { return *this = **this - in; }
    EERef &operator *=(uint8_t in)     { return *this = **this * in; }
    EERef &operator /=(uint8_t in)     { return *this = **this / in; }
    EERef &operator ^=(uint8_t in)     { return *this = **this ^ in; }
    EERef &operator %=(uint8_t in)     { return *this = **this % in; }
    EERef &operator &=(uint8_t in)     { return *this = **this & in; }
    EERef &operator |=(uint8_t in)     { return *this = **this | in; }
    EERef &operator <<=(uint8_t in)    { return *this = **this << in; }
    EERef &operator >>=(uint8_t in)    { return *this = **this >> in; }
    
    EERef &update( uint8_t in )        { return  in != *this ? *this = in : *this; }
    
    EERef &operator++()                { return *this += 1; }
    EERef &operator--()                { return *this -= 1; }
    
    uint8_t operator++ (int){ 
        uint8_t ret = **this;
        return ++(*this), ret;
    }

    uint8_t operator-- (int){ 
        uint8_t ret = **this;
        return --(*this), ret;
    }
    
    uint32_t index;
};

struct EEPtr{
    EEPtr(const uint32_t index) : index(index) {}
        
    operator int() const               { return index; }
    EEPtr &operator=( int in )         { return index = in, *this; }
    
    bool operator!=( const EEPtr &ptr ){ return index != ptr.index; }
    EERef operator*()                  { return index; }
    
    EEPtr& operator++()                { return ++index, *this; }
    EEPtr& operator--()                { return --index, *this; }
    EEPtr operator++ (int)             { return index++; }
    EEPtr operator-- (int)             { return index--; }

    int index;
};

class EEPROMClass {
public:
    EERef operator[](const uint32_t idx)    { return idx; }
    uint32_t read(uint32_t idx )            { return EERef(idx); }
    void write(uint32_t idx, uint8_t val)   { (EERef(idx)) = val; }
    void update(uint32_t idx, uint8_t val)  { EERef(idx).update(val); }
    void clear(void)                        { hal_flash_erase(HAL_PARTITION_PARAMETER_3, 0, 4096); }
    
    EEPtr begin()                           { return 0x00; }
    EEPtr end()                             { return length(); }
    uint32_t length()                       { hal_logic_partition_t res; hal_flash_info_get(HAL_PARTITION_PARAMETER_3, &res); return res.partition_length; }
    
    template< typename T > T & get(uint32_t idx, T &t)
    {
        READ(idx, t, T);
        return t;
    }

    template< typename T > const T & put(uint32_t idx, const T &t)
    {
        WRITE(idx, t, T);
        return t;
    }
};

__attribute__((unused)) static EEPROMClass EEPROM;

#endif /* ARDUINO_EEPROM_H */