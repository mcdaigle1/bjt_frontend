################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/logger/Logger.cpp 

OBJS += \
./src/logger/Logger.o 

CPP_DEPS += \
./src/logger/Logger.d 


# Each subdirectory must supply rules for building sources it contributes
src/logger/%.o: ../src/logger/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/mysql++ -I/usr/include/cppconn -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


