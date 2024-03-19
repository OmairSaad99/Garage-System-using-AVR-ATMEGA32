################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO_prog.c \
../EXTI_Prog.c \
../Garage_System_Prog.c \
../Global_prog.c \
../PWM_prog.c \
../Servo_prog.c \
../main.c 

OBJS += \
./CLCD_program.o \
./DIO_prog.o \
./EXTI_Prog.o \
./Garage_System_Prog.o \
./Global_prog.o \
./PWM_prog.o \
./Servo_prog.o \
./main.o 

C_DEPS += \
./CLCD_program.d \
./DIO_prog.d \
./EXTI_Prog.d \
./Garage_System_Prog.d \
./Global_prog.d \
./PWM_prog.d \
./Servo_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


