EXECUTABLE= main.elf
TARGET = main.hex

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
AS = arm-none-eabi-as
CP = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump


DEFINES = -DSTM32F4XX -DUSE_STDPERIPH_DRIVER -DSTM32F40_41xxx
MCU = cortex-m4 

MCFLAGS = -mcpu=$(MCU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork -fsingle-precision-constant

INCLUDES = -I../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/CMSIS/Device/ST/STM32F4xx/Include \
	   -I../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/CMSIS/Include \
	   -I../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/CMSIS/RTOS \
	   -I../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/STM32F4xx_StdPeriph_Driver/inc \
	   -I.

OPTIMIZE = -Os

LINK = stm32_flash.ld

LINKER = -Wl,-T,stm32_flash.ld
	   
CFLAGS = $(INCLUDES) $(MCFLAGS) $(DEFINES) $(INCLUDES) $(OPTIMIZE) $(LINKER)

STARTUP = startup_stm32f40xx.s

SOURCE = Video.c \
	 gpio_user.c \
	 main.c \
	 system_stm32f4xx.c \
	 interrupt.c \
	 ../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c \
	 ../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c \
	 ../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c \
	 ../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c \
	 ../STM32F4xx_DSP_StdPeriph_Lib_V1.2.0/Libraries/STM32F4xx_StdPeriph_Driver/src/misc.c

$(TARGET) : $(EXECUTABLE) 
	
	$(CP) -O ihex $^ $@

$(EXECUTABLE) :  $(SOURCE) $(STARTUP)

	$(CC)  $(CFLAGS) $^ -g -lm -lc -lnosys -o $@



