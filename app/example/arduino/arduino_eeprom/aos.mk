NAME := arduino_eeprom

$(NAME)_MBINS_TYPE := app
$(NAME)_VERSION := 0.0.1
$(NAME)_SUMMARY := Arduino EEPROM
$(NAME)_VENDER := MRNIU
$(NAME)_SOURCES := arduino_eeprom.cpp \
					arduino_exp_eeprom_clear.cpp \
					arduino_exp_eeprom_crc.cpp \
					arduino_exp_eeprom_get.cpp \
					arduino_exp_eeprom_iterations.cpp \
					arduino_exp_eeprom_put.cpp \
					arduino_exp_eeprom_read.cpp \
					arduino_exp_eeprom_update.cpp \
					arduino_exp_eeprom_write.cpp \

$(NAME)_COMPONENTS += osal_aos \
						arduino_framework \
						cplusplus \

GLOBAL_LDFLAGS += -lstdc++

GLOBAL_DEFINES += AOS_NO_WIFI \

GLOBAL_INCLUDES += ./

$(NAME)_INCLUDES := ./

GLOBAL_CXXFLAGS += -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16
