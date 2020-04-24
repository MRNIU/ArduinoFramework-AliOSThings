NAME := arduino_softwareserial

$(NAME)_MBINS_TYPE := app
$(NAME)_VERSION := 0.0.1
$(NAME)_SUMMARY := Arduino SoftwareSerial Library
$(NAME)_VENDER := MRNIU
$(NAME)_SOURCES := arduino_softwareserial.cpp \


$(NAME)_COMPONENTS += osal_aos \
						arduino_framework \
						cplusplus \

GLOBAL_LDFLAGS += -lstdc++

GLOBAL_DEFINES += AOS_NO_WIFI \
					AOS_COMP_VFS

GLOBAL_INCLUDES += ./

$(NAME)_INCLUDES := ./

GLOBAL_CXXFLAGS += -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16
