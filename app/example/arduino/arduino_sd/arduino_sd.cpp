/*
 * Copyright (C) 2019 MRNIU
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <stddef.h>
#include <ulog/ulog.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <arduino_exp_sd.h>

void arduino_exp_sd_isDirectory(void);
void printDirectory_isDirectory(File dir);
void arduino_exp_sd_rewindDirectory(void);
void printDirectory_rewindDirectory(File dir);
void arduino_exp_sd_openNextFile(void);
void printDirectory_openNextFile(File dir, int numTabs);

void setup() {
  return;
}

void loop() {
    printf("Test Begin !\n");

    if(aos_vfs_init())
        printf("aos_vfs_init error!\n");

    SD.mkdir("/sdcard/233");
    arduino_exp_sd_isDirectory();
    arduino_exp_sd_rewindDirectory();
    arduino_exp_sd_openNextFile();
    File test = SD.open("/sdcard/233/test.txt", FILE_WRITE);
    uint8_t a = 97;
    uint8_t b = 98;
    uint8_t c = 99;
    test.write(a);
    test.write(b);
    test.write(c);
    test.close();

    printf("Test End !\n");
    
    return;
}

void arduino_exp_sd_isDirectory()
{
    File root = SD.open("/sdcard");
    SD.begin();
    printDirectory_isDirectory(root);
    printf("Done!\n");
    SD.end();
    
    return;
}

void printDirectory_isDirectory(File dir)
{
    while(true) {
        File entry =  dir.openNextFile();
        if (!entry) {
            printf("**nomorefiles**\n");
            break;
        }
        printf("name: %s\n", entry.name());
        if(entry.isDirectory()) {
            printf("Dir: %s\n", entry.name());
            printDirectory_isDirectory(entry);
        } else {
            printf("file: %s\n", entry.name());
            printf("size: %ld\n", entry.size());
        }
    }
}

void arduino_exp_sd_rewindDirectory(void)
{
    File root;
    SD.begin();
    root = SD.open("/sdcard");
    printDirectory_rewindDirectory(root);
    printf("done!\n");
    SD.end();
    
    return;
}

void printDirectory_rewindDirectory(File dir)
{
    while(true) {
        File entry =  dir.openNextFile();
        if(!entry) {
            dir.rewindDirectory();
            break;
        }
        printf("name: %s\n", entry.name());
        if (entry.isDirectory()) {
            printDirectory_rewindDirectory(entry);
        } else {
            printf("size: %ld\n", entry.size());
        }
    }
    
    return;
}

void arduino_exp_sd_openNextFile(void)
{
    File root;
    SD.begin();
    root = SD.open("/sdcard");
    printDirectory_openNextFile(root, 0);
    delay(2000);
    printf("Rewinding, and repeating below:\n" );
    delay(2000);
    root.rewindDirectory();
    printDirectory_openNextFile(root, 0);
    root.close();
    SD.end();
    
    return;
}

void printDirectory_openNextFile(File dir, int numTabs)
{
    while (true) {
        File entry = dir.openNextFile();
        if (! entry){
            if (numTabs == 0)
                printf("** Done **\n");
            return;
        }
        printf("name: %s\n", entry.name());
        if (entry.isDirectory()) {
            printDirectory_openNextFile(entry, numTabs + 1);
        } else {
            printf("size: %ld\n", entry.size());
        }
        entry.close();
    }
    
    return;
}
