BUILD = ./build
TEST = ./test
SRC = ./src
LIB = ./lib

CMP = g++
FLAGS = -Wall - Wextra -Werror

all:
	make clean
	make init
	make ArrayBased2DArray
	make VecBased2DArray

ArrayBased2DArray:  
	cd $(SRC)/ArrTwoDArray; make;
	cp $(SRC)/ArrTwoDArray/TwoDArray.o $(TEST)/;
	cp $(SRC)/ArrTwoDArray/TwoDArray.h $(TEST)/;
	cd $(TEST); make ArrayBased_test;
	rm -f $(TEST)/TwoDArray.*

VecBased2DArray:
	cd $(SRC)/VecTwoDArray; make;
	cp $(SRC)/VecTwoDArray/TwoDArray.o $(TEST)/;
	cp $(SRC)/VecTwoDArray/TwoDArray.h $(TEST)/;
	cd $(TEST); make VecBased_test;
	rm -f $(TEST)/TwoDArray.*

init:
	mkdir -p $(BUILD) $(TEST) $(SRC) $(LIB)

clean:
	cd $(SRC)/ArrTwoDArray; make clean;
	rm -rf $(BUILD)
