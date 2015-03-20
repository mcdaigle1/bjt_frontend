################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/database/Database.cpp \
../src/database/DbAccess.cpp \
../src/database/DbConnectionPool.cpp \
../src/database/DealerHandAccess.cpp \
../src/database/DealerHitRuleAccess.cpp \
../src/database/GameAccess.cpp \
../src/database/PlayerHandAccess.cpp \
../src/database/PlayerHitRuleAccess.cpp \
../src/database/ShoeAccess.cpp \
../src/database/ShoeOneAccess.cpp \
../src/database/ShoeSixAccess.cpp \
../src/database/ShoeSixDatabase.cpp \
../src/database/ShoeTwoAccess.cpp \
../src/database/Storable.cpp 

OBJS += \
./src/database/Database.o \
./src/database/DbAccess.o \
./src/database/DbConnectionPool.o \
./src/database/DealerHandAccess.o \
./src/database/DealerHitRuleAccess.o \
./src/database/GameAccess.o \
./src/database/PlayerHandAccess.o \
./src/database/PlayerHitRuleAccess.o \
./src/database/ShoeAccess.o \
./src/database/ShoeOneAccess.o \
./src/database/ShoeSixAccess.o \
./src/database/ShoeSixDatabase.o \
./src/database/ShoeTwoAccess.o \
./src/database/Storable.o 

CPP_DEPS += \
./src/database/Database.d \
./src/database/DbAccess.d \
./src/database/DbConnectionPool.d \
./src/database/DealerHandAccess.d \
./src/database/DealerHitRuleAccess.d \
./src/database/GameAccess.d \
./src/database/PlayerHandAccess.d \
./src/database/PlayerHitRuleAccess.d \
./src/database/ShoeAccess.d \
./src/database/ShoeOneAccess.d \
./src/database/ShoeSixAccess.d \
./src/database/ShoeSixDatabase.d \
./src/database/ShoeTwoAccess.d \
./src/database/Storable.d 


# Each subdirectory must supply rules for building sources it contributes
src/database/%.o: ../src/database/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/include/openssl -I/usr/include/mysql -I/usr/include/mysql++ -I/usr/include/c++/4.6.3/i686-redhat-linux -I/usr/lib/gcc/i686-redhat-linux/4.6.3/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


