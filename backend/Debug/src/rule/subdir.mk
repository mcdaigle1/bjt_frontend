################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/rule/BetRule.cpp \
../src/rule/DealerHitRule.cpp \
../src/rule/PlayerHitRule.cpp 

OBJS += \
./src/rule/BetRule.o \
./src/rule/DealerHitRule.o \
./src/rule/PlayerHitRule.o 

CPP_DEPS += \
./src/rule/BetRule.d \
./src/rule/DealerHitRule.d \
./src/rule/PlayerHitRule.d 


# Each subdirectory must supply rules for building sources it contributes
src/rule/%.o: ../src/rule/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/include/openssl -I/usr/include/mysql -I/usr/include/mysql++ -I/usr/include/c++/4.6.3/i686-redhat-linux -I/usr/lib/gcc/i686-redhat-linux/4.6.3/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


