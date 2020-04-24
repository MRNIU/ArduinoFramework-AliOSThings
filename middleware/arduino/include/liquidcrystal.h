/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_LCD_H
#define ARDUINO_LCD_H

#include <string>

#ifdef __cplusplus
extern"C" {
#endif /* __cplusplus */ 

#include <../platform/mcu/stm32l475/Drivers/BSP/Components/st7789h2/st7789h2.h>
#include <../board/developerkit/aos/st7789.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

class LiquidCrystal {
private:
    uint16_t curr_x;
    uint16_t curr_y;
public:
    LiquidCrystal(void);
    void init(void);
    void begin(void);
    void clear(void);
    void home(void);
    void noDisplay(void);
    void display(void);
    void setCursor(uint16_t Xpos, uint16_t Ypos);
    size_t write(uint16_t Xpos, uint16_t Ypos, uint8_t data);
};

#endif /* ARDUINO_LCD_H */