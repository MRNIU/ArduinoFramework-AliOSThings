/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_softwareserial.h>

void setup() {
  return;
}

void loop() {
    printf("Test Begin !\n");
    
    test();

    printf("End!\n");

    // arduino_exp_ss_SoftwareSerial();
    // arduino_exp_ss_available();
    // arduino_exp_ss_begin();
    // arduino_exp_ss_isListening();
    // arduino_exp_ss_overflow();
    // arduino_exp_ss_peek();
    // arduino_exp_ss_read();
    // arduino_exp_ss_write();
    // arduino_exp_ss_listen();

    return;
}

void test(void)
{
    SoftwareSerial SS(1);
    SS.begin(9600);
    SS.listen();
    
    printf("isls: %d\n", SS.isListening());
    printf("peek: %d\n", SS.peek());
    printf("read: %d\n", SS.read());
    printf("peek: %d\n", SS.peek());
    printf("write: %d\n", SS.write(23));
    printf("available: %d\n", SS.available());

    SS.stopListening();
    
    return;
}

void arduino_exp_ss_SoftwareSerial(void)
{
    const byte port = 1;
    SoftwareSerial mySerial(port);
    return;
}

void arduino_exp_ss_available(void)
{
    const byte port = 1;
    SoftwareSerial mySerial =  SoftwareSerial(port);
    mySerial.begin(9600);
    while(1) {
        if(mySerial.available() > 0){
            mySerial.read();
        }
    }
    return;
}

void arduino_exp_ss_begin(void)
{
    const byte port = 1;
    SoftwareSerial mySerial =  SoftwareSerial(port);
    mySerial.begin(9600);
    return;
}

void arduino_exp_ss_isListening(void)
{
    const byte port = 1;
    SoftwareSerial portOne(port);
    portOne.begin(9600);

    while(1) {
        if(portOne.isListening())
            printf("Port One is listening!\n"); 
    }
    return;
}

void arduino_exp_ss_overflow(void)
{   
    const byte port = 1;
    SoftwareSerial portOne(port);
    portOne.begin(9600);

    while(1){
        if (portOne.overflow())
            printf("SoftwareSerial overflow!\n");
    }
    return;
}

void arduino_exp_ss_peek(void)
{
    const byte port = 1;
    SoftwareSerial mySerial =  SoftwareSerial(port);
    mySerial.begin(9600);
    char c = mySerial.peek();
    printf("c: %c\n", c);
    return;
}

void arduino_exp_ss_read(void)
{
    const byte port = 1;
    SoftwareSerial mySerial =  SoftwareSerial(port);
    mySerial.begin(9600);
    char c = mySerial.read();
    printf("c: %c\n", c);
    return;
}

void arduino_exp_ss_write(void)
{
    const byte port = 1;
    SoftwareSerial mySerial =  SoftwareSerial(port);
    mySerial.begin(9600);
    char c = mySerial.write(45);
    int bytesSent = mySerial.write("hello");
    printf("c: %c\tbytesSent: %d\n", c, bytesSent);
    return;
}

void arduino_exp_ss_listen(void)
{
    const byte port1 = 1;
    const byte port2 = 2;
    SoftwareSerial portOne(port1);
    SoftwareSerial portTwo(port2);

    portOne.begin(9600);
    portTwo.begin(9600);

    portOne.listen();

    if(portOne.isListening()) {
        printf("Port One is listening!\n"); 
    } else {
        printf("Port One is not listening!\n"); 
    }

    if(portTwo.isListening()) {
        printf("Port Two is listening!\n"); 
    } else {
        printf("Port Two is not listening!\n");
    }
    return;
}
