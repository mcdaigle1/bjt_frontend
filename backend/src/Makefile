#############################################################
# Copyright 2012 Blue Cask Software. All rights reserved.
#
# THIS PROGRAM IS CONFIDENTIAL AND PROPRIETARY TO BLUE CASK
# SOFTWARE.  Any unauthorized use, reproduction, modification, or
# disclosure of this program is strictly prohibited without the
# express written permission of an authorized representative of
# Blue Cask Software.
#############################################################

PROGRAM = blackjack

INC_DIRS_COMMON = \
	-I/usr/include/ \
	-I/usr/include/c++/4.6.3/ \
	-I/usr/include/c++/4.6.3/backward/ \
	-I/usr/include/mysql++/ \
	-I/usr/include/mysql/ \
	-I/usr/include/cppconn/ \
	-I/usr/include/openssl/ \
	-I/usr/local/include/
	
#	-I/usr/include/hashlib++/ 

INC_DIRS_64 = \
	-I/usr/include/c++/4.6.3/x86_64-redhat-linux/ \
	-I/usr/lib/gcc/x86_64-redhat-linux/4.6.3/include/ 
	
INC_DIRS_32 = \
	-I/usr/include/c++/4.6.3/i686-redhat-linux/ \
	-I/usr/lib/gcc/i686-redhat-linux/4.6.3/include 

LIB_DIRS_COMMON = \
	-L/usr/lib \
	-L/usr/lib/mysql \
	-L/usr/local/lib \
	-lmysqlpp 

#	-lhl++
	
LIB_DIRS_64 = \
	-L/usr/lib64/openssl \
	-L/usr/lib64
	
LIB_DIRS_64 =

BD = ../build

LIBS =

CXXOBJECTS = $(CXXSOURCES:.cpp=.o)  # expands to list of object files
CXXFLAGS = $(INC_DIRS_COMMON) $(INC_DIRS_64)
CXXFLAGS_32 = $(INC_DIRS_COMMON) $(INC_DIRS_32)
CXX = g++ -std=gnu++0x

LDFLAGS = $(LIB_DIRS_COMMON) $(LIB_DIRS_64) $(LIBS)
LDFLAGS_32 = $(LIB_DIRS_COMMON) $(LIB_DIRS_32) $(LIBS)

OBJECT_FILES = \
	$(BD)/main.o $(BD)/BaseException.o $(BD)/Logger.o $(BD)/Md5Util.o $(BD)/RandomUtil.o \
	$(BD)/VectorUtil.o $(BD)/StringUtil.o \
	$(BD)/Database.o $(BD)/DbAccess.o $(BD)/GameAccess.o $(BD)/PlayerHandAccess.o \
	$(BD)/DealerHandAccess.o $(BD)/ShoeAccess.o $(BD)/Storable.o \
	$(BD)/PlayerHitRule.o $(BD)/DealerHitRule.o $(BD)/BetRule.o \
	$(BD)/PlayerHitRuleAccess.o $(BD)/DealerHitRuleAccess.o $(BD)/Card.o $(BD)/Shoe.o \
	$(BD)/Hand.o $(BD)/PlayerHand.o $(BD)/DealerHand.o $(BD)/Game.o $(BD)/GameController.o \
	$(BD)/ShoeController.o

all: blackjack

blackjack: ${OBJECT_FILES}
	$(CXX) $(CXXFLAGS) ${OBJECT_FILES} $(LDFLAGS) -o blackjack
	
blackjack_32: ${OBJECT_FILES}
	$(CXX) $(CXXFLAGS_32) ${OBJECT_FILES} $(LDFLAGS) -o blackjack

$(BD)/main.o: main.cpp ./utility/Logger.h ./database/Database.h ./deck/Shoe.h ./game/Game.h \
		./database/GameAccess.h ./deck/ShoeController.h ./exception/BaseException.h \
		./exception/CommandArgumentException.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BD)/main.o

$(BD)/Logger.o: ./utility/Logger.cpp ./utility/Logger.h ./exception/LoggerException.h
	$(CXX) $(CXXFLAGS) -c ./utility/Logger.cpp -o $(BD)/Logger.o
	
$(BD)/Md5Util.o: ./utility/Md5Util.cpp ./utility/Md5Util.h ./exception/UtilityException.h
	$(CXX) $(CXXFLAGS) -c ./utility/Md5Util.cpp -o $(BD)/Md5Util.o	
	
$(BD)/RandomUtil.o: ./utility/RandomUtil.cpp ./utility/RandomUtil.h
	$(CXX) $(CXXFLAGS) -c ./utility/RandomUtil.cpp -o $(BD)/RandomUtil.o
	
$(BD)/VectorUtil.o: ./utility/VectorUtil.cpp ./utility/VectorUtil.h ./utility/Logger.h \
		./utility/StringUtil.h
	$(CXX) $(CXXFLAGS) -c ./utility/VectorUtil.cpp -o $(BD)/VectorUtil.o

$(BD)/StringUtil.o: ./utility/StringUtil.cpp ./utility/StringUtil.h
	$(CXX) $(CXXFLAGS) -c ./utility/StringUtil.cpp -o $(BD)/StringUtil.o
	
$(BD)/BaseException.o: ./exception/BaseException.cpp ./exception/BaseException.h
	$(CXX) $(CXXFLAGS) -c ./exception/BaseException.cpp -o $(BD)/BaseException.o
	
$(BD)/Database.o: ./database/Database.cpp ./database/Database.h ./exception/DatabaseException.h \
		./utility/Logger.h
	$(CXX) $(CXXFLAGS) -c ./database/Database.cpp -o $(BD)/Database.o
	
$(BD)/DbAccess.o: ./database/DbAccess.cpp ./database/DbAccess.h ./database/Database.h \
		./exception/DatabaseException.h ./exception/DbDuplicateEntryException.h \
		./utility/Logger.h
	$(CXX) $(CXXFLAGS) -c ./database/DbAccess.cpp -o $(BD)/DbAccess.o
	
$(BD)/GameAccess.o: ./database/GameAccess.cpp ./database/GameAccess.h ./database/DbAccess.h
	$(CXX) $(CXXFLAGS) -c ./database/GameAccess.cpp -o $(BD)/GameAccess.o

$(BD)/PlayerHandAccess.o: ./database/PlayerHandAccess.cpp ./database/PlayerHandAccess.h \
		./database/DbAccess.h ./utility/Logger.h ./exception/InvalidArgumentException.h
	$(CXX) $(CXXFLAGS) -c ./database/PlayerHandAccess.cpp -o $(BD)/PlayerHandAccess.o
	
$(BD)/DealerHandAccess.o: ./database/DealerHandAccess.cpp ./database/DealerHandAccess.h \
		./database/DbAccess.h ./utility/Logger.h ./exception/InvalidArgumentException.h
	$(CXX) $(CXXFLAGS) -c ./database/DealerHandAccess.cpp -o $(BD)/DealerHandAccess.o

$(BD)/ShoeAccess.o: ./database/ShoeAccess.cpp ./database/ShoeAccess.h \
 		./database/DbAccess.h ./utility/Logger.h ./exception/ShoeException.h \
 		./deck/Shoe.h
	$(CXX) $(CXXFLAGS) -c ./database/ShoeAccess.cpp -o $(BD)/ShoeAccess.o
	
#$(BD)/ShoeOneAccess.o: ./database/ShoeOneAccess.cpp ./database/ShoeOneAccess.h \
# 		./database/DbAccess.h ./database/ShoeAccess.h
#	$(CXX) $(CXXFLAGS) -c ./database/ShoeOneAccess.cpp -o $(BD)/ShoeOneAccess.o
	
#$(BD)/ShoeTwoAccess.o: ./database/ShoeTwoAccess.cpp ./database/ShoeTwoAccess.h \
# 		./database/DbAccess.h  ./database/ShoeAccess.h
#	$(CXX) $(CXXFLAGS) -c ./database/ShoeTwoAccess.cpp -o $(BD)/ShoeTwoAccess.o
	
#$(BD)/ShoeSixAccess.o: ./database/ShoeSixAccess.cpp ./database/ShoeSixAccess.h \
# 		./database/DbAccess.h  ./database/ShoeAccess.h
#	$(CXX) $(CXXFLAGS) -c ./database/ShoeSixAccess.cpp -o $(BD)/ShoeSixAccess.o	
	
$(BD)/PlayerHitRuleAccess.o: ./database/PlayerHitRuleAccess.cpp ./database/PlayerHitRuleAccess.h \
 		./exception/RuleException.h ./database/DbAccess.h
	$(CXX) $(CXXFLAGS) -c ./database/PlayerHitRuleAccess.cpp -o $(BD)/PlayerHitRuleAccess.o	
	
$(BD)/DealerHitRuleAccess.o: ./database/DealerHitRuleAccess.cpp ./database/DealerHitRuleAccess.h \
 		./exception/RuleException.h ./database/DbAccess.h
	$(CXX) $(CXXFLAGS) -c ./database/DealerHitRuleAccess.cpp -o $(BD)/DealerHitRuleAccess.o	
	
$(BD)/Storable.o: ./database/Storable.cpp ./database/Storable.h ./utility/Logger.h
	$(CXX) $(CXXFLAGS) -c ./database/Storable.cpp -o $(BD)/Storable.o

$(BD)/PlayerHitRule.o: ./rule/PlayerHitRule.cpp ./rule/PlayerHitRule.h ./rule/HitRule.h \
 		./database/PlayerHitRuleAccess.h ./utility/Logger.h ./utility/StringUtil.h \
 		./exception/RuleException.h
	$(CXX) $(CXXFLAGS) -c ./rule/PlayerHitRule.cpp -o $(BD)/PlayerHitRule.o		

$(BD)/DealerHitRule.o: ./rule/DealerHitRule.cpp ./rule/DealerHitRule.h ./rule/HitRule.h \
		./database/DealerHitRuleAccess.h ./utility/Logger.h ./utility/StringUtil.h \
		./exception/RuleException.h
	$(CXX) $(CXXFLAGS) -c ./rule/DealerHitRule.cpp -o $(BD)/DealerHitRule.o
	
$(BD)/BetRule.o: ./rule/BetRule.cpp ./rule/BetRule.h ./database/Storable.h \
		./utility/Logger.h ./utility/StringUtil.h \
		./exception/RuleException.h
	$(CXX) $(CXXFLAGS) -c ./rule/BetRule.cpp -o $(BD)/BetRule.o

$(BD)/Shoe.o: ./deck/Shoe.cpp ./deck/Shoe.h ./database/Storable.h ./database/ShoeAccess.h \
		./deck/Card.h ./utility/Md5Util.h \
		./utility/Logger.h ./utility/RandomUtil.h ./utility/StringUtil.h ./exception/ShoeException.h \
		./exception/InvalidArgumentException.h ./exception/DbDuplicateEntryException.h
	$(CXX) $(CXXFLAGS) -c ./deck/Shoe.cpp -o $(BD)/Shoe.o 

$(BD)/Card.o: ./deck/Card.cpp ./deck/Card.h ./database/Storable.h ./exception/CardException.h \
		./exception/InvalidArgumentException.h ./utility/Logger.h
	$(CXX) $(CXXFLAGS) -c ./deck/Card.cpp -o $(BD)/Card.o
	
$(BD)/Game.o: ./game/Game.cpp ./game/Game.h ./database/Storable.h ./game/PlayerHand.h ./game/DealerHand.h \
		./deck/Shoe.h ./rule/PlayerHitRule.h \
		./rule/DealerHitRule.h ./rule/BetRule.h ./utility/Logger.h ./utility/RandomUtil.h \
		./utility/StringUtil.h ./utility/VectorUtil.h ./database/GameAccess.h ./database/PlayerHandAccess.h \
		./database/DealerHandAccess.h ./database/ShoeTwoAccess.h \
		./database/ShoeSixAccess.h ./exception/GameReserveException.h ./exception/DatabaseException.h
	$(CXX) $(CXXFLAGS) -c ./game/Game.cpp -o $(BD)/Game.o

$(BD)/Hand.o: ./game/Hand.cpp ./game/Hand.h ./database/Storable.h ./deck/Card.h \
		./exception/HandException.h ./utility/Logger.h ./utility/VectorUtil.h 
	$(CXX) $(CXXFLAGS) -c ./game/Hand.cpp -o $(BD)/Hand.o
	
$(BD)/PlayerHand.o: ./game/PlayerHand.cpp ./game/PlayerHand.h ./game/Hand.h ./deck/Card.h \
		./database/PlayerHandAccess.h ./exception/HandException.h ./utility/Logger.h ./utility/VectorUtil.h 
	$(CXX) $(CXXFLAGS) -c ./game/PlayerHand.cpp -o $(BD)/PlayerHand.o

$(BD)/DealerHand.o: ./game/DealerHand.cpp ./game/DealerHand.h ./game/Hand.h ./deck/Card.h \
		./database/DealerHandAccess.h ./exception/HandException.h ./utility/Logger.h ./utility/VectorUtil.h
	$(CXX) $(CXXFLAGS) -c ./game/DealerHand.cpp -o $(BD)/DealerHand.o
	
$(BD)/GameController.o: ./game/GameController.cpp ./game/GameController.h ./database/GameAccess.h ./rule/PlayerHitRule.h \
		./utility/Logger.h ./utility/RandomUtil.h ./utility/StringUtil.h
	$(CXX) $(CXXFLAGS) -c ./game/GameController.cpp -o $(BD)/GameController.o
	
$(BD)/ShoeController.o: ./deck/ShoeController.cpp ./deck/ShoeController.h \
		./deck/Shoe.h ./database/ShoeAccess.h ./exception/DbDuplicateEntryException.h \
		./utility/Logger.h ./utility/RandomUtil.h ./utility/StringUtil.h
	$(CXX) $(CXXFLAGS) -c ./deck/ShoeController.cpp -o $(BD)/ShoeController.o

# Clean target: "make -f Makefile.Linux clean" to remove unwanted objects and executables.
#

clean:
	$(RM) $(BD)/*.o