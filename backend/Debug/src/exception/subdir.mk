################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/exception/BaseException.cpp 

OBJS += \
./src/exception/BaseException.o 

CPP_DEPS += \
./src/exception/BaseException.d 


# Each subdirectory must supply rules for building sources it contributes
src/exception/%.o: ../src/exception/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/include/openssl -I/usr/include/mysql -I/usr/include/mysql++ -I/usr/include/c++/4.6.3/i686-redhat-linux -I/usr/lib/gcc/i686-redhat-linux/4.6.3/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


