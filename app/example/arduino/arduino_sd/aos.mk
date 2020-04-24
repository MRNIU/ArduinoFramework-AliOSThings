NAME := arduino_sd

$(NAME)_MBINS_TYPE := app
$(NAME)_VERSION := 0.0.1
$(NAME)_SUMMARY := Arduino SD Library
$(NAME)_VENDER := MRNIU
$(NAME)_SOURCES := arduino_sd.cpp \


$(NAME)_COMPONENTS += osal_aos \
						arduino_framework \
						cplusplus \
						fatfs \

GLOBAL_LDFLAGS += -lstdc++

GLOBAL_DEFINES += AOS_NO_WIFI \
					CONFIG_AOS_FATFS_SUPPORT_MMC \
					AOS_COMP_VFS \

GLOBAL_INCLUDES += ./

$(NAME)_INCLUDES := ./

GLOBAL_CXXFLAGS += -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16
