BUILD = ./build
TEST = ./test
SRC = ./src
LIB = ./lib

CMP = g++
FLAGS = -Wall - Wextra -Werror

all:
	make init
	make clean	
	make ArrayBased2DArray

ArrayBased2DArray:  
	cd $(SRC)/ArrTwoDArray; make;

init:
	mkdir -p $(BUILD) $(TEST) $(SRC) $(LIB)

clean:
	cd $(SRC)/ArrTwoDArray; make clean;
