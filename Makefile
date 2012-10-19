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

ArrayBased2DArray:  
	cd $(SRC)/ArrTwoDArray; make;
	cp $(SRC)/ArrTwoDArray/TwoDArray.o $(TEST)/;
	cp $(SRC)/ArrTwoDArray/TwoDArray.h $(TEST)/;
	cd $(TEST); make;
	rm -f $(TEST)/TwoDArray.*

init:
	mkdir -p $(BUILD) $(TEST) $(SRC) $(LIB)

clean:
	cd $(SRC)/ArrTwoDArray; make clean;
	rm -rf $(BUILD)
