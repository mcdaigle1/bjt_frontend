################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/deck/Card.cpp \
../src/deck/Shoe.cpp \
../src/deck/ShoeController.cpp 

OBJS += \
./src/deck/Card.o \
./src/deck/Shoe.o \
./src/deck/ShoeController.o 

CPP_DEPS += \
./src/deck/Card.d \
./src/deck/Shoe.d \
./src/deck/ShoeController.d 


# Each subdirectory must supply rules for building sources it contributes
src/deck/%.o: ../src/deck/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/include/openssl -I/usr/include/mysql -I/usr/include/mysql++ -I/usr/include/c++/4.6.3/i686-redhat-linux -I/usr/lib/gcc/i686-redhat-linux/4.6.3/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


