################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/game/DealerHand.cpp \
../src/game/Game.cpp \
../src/game/GameController.cpp \
../src/game/Hand.cpp \
../src/game/PlayerHand.cpp 

OBJS += \
./src/game/DealerHand.o \
./src/game/Game.o \
./src/game/GameController.o \
./src/game/Hand.o \
./src/game/PlayerHand.o 

CPP_DEPS += \
./src/game/DealerHand.d \
./src/game/Game.d \
./src/game/GameController.d \
./src/game/Hand.d \
./src/game/PlayerHand.d 


# Each subdirectory must supply rules for building sources it contributes
src/game/%.o: ../src/game/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/include/openssl -I/usr/include/mysql -I/usr/include/mysql++ -I/usr/include/c++/4.6.3/i686-redhat-linux -I/usr/lib/gcc/i686-redhat-linux/4.6.3/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


