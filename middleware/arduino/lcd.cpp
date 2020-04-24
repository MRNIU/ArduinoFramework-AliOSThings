/*
 * Copyright (C) 2019 MRNIU
 */

#include <include/liquidcrystal.h>

LiquidCrystal::LiquidCrystal(void)
{
    return;
}

void LiquidCrystal::init(void)
{
    st7789_init();
    return;
}

void LiquidCrystal::begin(void)
{
    this->init();
    return;
}

void LiquidCrystal::clear(void)
{
    for(int i = 0; i<240; i++)
        for(int j = 0; j<240; j++){
            ST7789H2_WritePixel(i, j, 0xFFFF);
        }
    ST7789H2_SetCursor(0, 0);
    this->curr_x = 0;
    this->curr_y = 0;
    return;
}

void LiquidCrystal::home(void)
{
    ST7789H2_SetCursor(0, 0);
    this->curr_x = 0;
    this->curr_y = 0;
    return;
}

void LiquidCrystal::noDisplay(void)
{
    ST7789H2_DisplayOff();
    return;
}

void LiquidCrystal::display()
{
    ST7789H2_DisplayOn();
    return;
}

void LiquidCrystal::setCursor(uint16_t Xpos, uint16_t Ypos)
{
    ST7789H2_SetCursor(Xpos, Ypos);
    this->curr_x = Xpos;
    this->curr_y = Ypos;
    return;
}

size_t LiquidCrystal::write(uint16_t Xpos, uint16_t Ypos, uint8_t data)
{
    ST7789H2_WritePixel(Xpos, Ypos, data);
    return 0;
}
