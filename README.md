# ArduinoFramework-AliOSThings

这是为 AliOS-Things 编写的 Arduino 框架，目标是能够在 AliOS 上直接运行 Arduino 程序

感谢 Alibaba Summer of Code.

## 使用方法 Usage

app 目录下是例程

middleware 目录下是实现文件

要使用 Framework，你需要：

1. 将 `middleware/arduino` 文件夹移动到 `AliOS-Things/middleware`

2. 将 `app/example/arduino` 文件夹移动到 ``AliOS-Things/app/example/arduino`

3. 将 `app/example/Config.in` 文件追加到 ``AliOS-Things/app/example/Config.in` 中

    ```
    config AOS_APP_EXAMPLE
        bool "Builtin Examples"
    
    if AOS_APP_EXAMPLE
    choice
        prompt "Select example"
    
    # ...
    # Other source
    # ...
    
    source "app/example/arduino/arduino_base/Config.in"
    if AOS_APP_ARDUINO_BASE
        config AOS_BUILD_APP
            default "arduino.arduino_base"
    endif
    
    source "app/example/arduino/arduino_eeprom/Config.in"
    if AOS_APP_ARDUINO_EEPROM
        config AOS_BUILD_APP
            default "arduino.arduino_eeprom"
    endif
    
    source "app/example/arduino/arduino_sd/Config.in"
    if AOS_APP_ARDUINO_SD
        config AOS_BUILD_APP
            default "arduino.arduino_sd"
    endif
    
    source "app/example/arduino/arduino_lcd/Config.in"
    if AOS_APP_ARDUINO_LCD
        config AOS_BUILD_APP
            default "arduino.arduino_lcd"
    endif
    
    source "app/example/arduino/arduino_softwareserial/Config.in"
    if AOS_APP_ARDUINO_SOFTWARESERIAL
        config AOS_BUILD_APP
            default "arduino.arduino_softwareserial"
    endif
    
    source "app/example/arduino/arduino_wire/Config.in"
    if AOS_APP_ARDUINO_WIRE
        config AOS_BUILD_APP
            default "arduino.arduino_wire"
    endif
    
    endchoice
    endif
    
    ```

4. 然后就可以愉快的使用了！











## 贡献者 Contributor

[MRNIU](https://github.com/MRNIU)