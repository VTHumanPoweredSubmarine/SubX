################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../accelerometer.cpp \
../datalogging.cpp 

CMD_SRCS += \
../msp432p401r.cmd 

C_SRCS += \
../i2c_driver.c \
../main.c \
../pressure.c \
../rpm.c \
../startup_msp432p401r_ccs.c \
../system_msp432p401r.c \
../timer_driver.c \
../uart_driver.c 

C_DEPS += \
./i2c_driver.d \
./main.d \
./pressure.d \
./rpm.d \
./startup_msp432p401r_ccs.d \
./system_msp432p401r.d \
./timer_driver.d \
./uart_driver.d 

OBJS += \
./accelerometer.obj \
./datalogging.obj \
./i2c_driver.obj \
./main.obj \
./pressure.obj \
./rpm.obj \
./startup_msp432p401r_ccs.obj \
./system_msp432p401r.obj \
./timer_driver.obj \
./uart_driver.obj 

CPP_DEPS += \
./accelerometer.d \
./datalogging.d 

OBJS__QUOTED += \
"accelerometer.obj" \
"datalogging.obj" \
"i2c_driver.obj" \
"main.obj" \
"pressure.obj" \
"rpm.obj" \
"startup_msp432p401r_ccs.obj" \
"system_msp432p401r.obj" \
"timer_driver.obj" \
"uart_driver.obj" 

C_DEPS__QUOTED += \
"i2c_driver.d" \
"main.d" \
"pressure.d" \
"rpm.d" \
"startup_msp432p401r_ccs.d" \
"system_msp432p401r.d" \
"timer_driver.d" \
"uart_driver.d" 

CPP_DEPS__QUOTED += \
"accelerometer.d" \
"datalogging.d" 

CPP_SRCS__QUOTED += \
"../accelerometer.cpp" \
"../datalogging.cpp" 

C_SRCS__QUOTED += \
"../i2c_driver.c" \
"../main.c" \
"../pressure.c" \
"../rpm.c" \
"../startup_msp432p401r_ccs.c" \
"../system_msp432p401r.c" \
"../timer_driver.c" \
"../uart_driver.c" 


