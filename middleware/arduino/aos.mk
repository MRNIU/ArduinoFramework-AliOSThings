NAME := arduino_framework
$(NAME)_MBINS_TYPE := kernel
$(NAME)_VERSION := 0.0.1
$(NAME)_SUMMARY := Arduino framework
$(NAME)_VENDER := MRNIU
$(NAME)_SOURCES := linkedlist.c \
					digital_io.cpp \
					analog_io.cpp \
					time.cpp \
					math.cpp \
					interrupt.cpp \
					sd.cpp \
					lcd.cpp \
					softwareserial.cpp \
					wire.cpp \
					interface.cpp

GLOBAL_DEFINES += AOS_NO_WIFI \
					AOS_COMP_VFS \
					CONFIG_AOS_FATFS_SUPPORT_MMC \

$(NAME)_COMPONENTS := cli \
						yloop \
						cplusplus \
						fatfs \
						atparser \
						athost \
						netmgr \
						device_sal_bk7231 \
						sal \

ATHOSTAPP_CONFIG_ATPARSER ?= y
ATHOSTAPP_CONFIG_MQTTREPORT ?= y

GLOBAL_INCLUDES += ./

$(NAME)_INCLUDES := ./

GLOBAL_LDFLAGS += -lstdc++