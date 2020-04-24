/*
 * Copyright (C) 2019 MRNIU
 */

#ifndef ARDUINO_PORT_H
#define ARDUINO_PORT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// Developer Kit start
#define ARD_0    3  // PA3
#define ARD_1    2  // PA2
#define ARD_2    62  // PD14
#define ARD_3    70  // PE6
#define ARD_4    59  // PD11
#define ARD_5    69  // PE5
#define ARD_6    68  // PE4
#define ARD_7    64  // PE0

#define ARD_8    43  // PC11
#define ARD_9    42  // PC10
#define ARD_10    48  // PD0
#define ARD_11    33  // PC1
#define ARD_12    51  // PD3
#define ARD_13    9  // PA9
#define ARD_GND1  // GND
#define ARD_AREF  // 3.3V output
#define ARD_A4_SDA  41  // PC9
#define ARD_A5_SCL  32  // PC0

#define ARD_A0    34  // PC2
#define ARD_A1    35  // PC3
#define ARD_A2    39  // PC7
#define ARD_A3    44  // PC12
#define ARD_A4    49  // PD1
#define ARD_A5    55 // PD7

#define ARD_VIN  // 5V output
#define ARD_GND2  // GND
#define ARD_GND3  // GND
#define ARD_5V  // 5V output, need set J905
#define ARD_3_3V  // 3.3V output
#define ARD_RESET  // Reset MCU
#define ARD_IOREF  // 3V output
#define ARD_NULL // void
// Developer Kit end

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif /* ARDUINO_PORT_H */
