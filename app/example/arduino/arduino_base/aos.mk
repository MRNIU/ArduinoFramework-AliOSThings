NAME := arduino_base

$(NAME)_MBINS_TYPE := app
$(NAME)_VERSION := 0.0.1
$(NAME)_SUMMARY := Arduino Base Functions
$(NAME)_VENDER := MRNIU
$(NAME)_SOURCES := arduino_base.cpp \
					arduino_exp_analog_read.cpp \
					arduino_exp_analog_write.cpp \
					arduino_exp_digitalio_pinmode.cpp \
					arduino_exp_digitalio_read.cpp \
					arduino_exp_digitalio_write.cpp \
					arduino_exp_time_delay.cpp \
					arduino_exp_time_delayMicroseconds.cpp \
					arduino_exp_time_micros.cpp \
					arduino_exp_time_millis.cpp \

$(NAME)_COMPONENTS += osal_aos \
						cplusplus \
						arduino_framework \

GLOBAL_LDFLAGS += -lstdc++

GLOBAL_DEFINES += AOS_NO_WIFI \

GLOBAL_INCLUDES += ./

$(NAME)_INCLUDES := ./

GLOBAL_CXXFLAGS += -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16
