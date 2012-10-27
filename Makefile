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
	make Sparse2DArray

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


Sparse2DArray:
	cd $(SRC)/SparseTwoDArray; make;
	cp $(SRC)/SparseTwoDArray/TwoDArray.o $(TEST)/;
	cp $(SRC)/SparseTwoDArray/TwoDArray.h $(TEST)/;
	cp $(SRC)/SparseTwoDArray/Node.o $(TEST)/;
	cp $(SRC)/SparseTwoDArray/Node.h $(TEST)/;
	cd $(TEST); make SparseBased_test;
	rm -f $(TEST)/TwoDArray.*
	rm -f $(TEST)/Node.*


init:
	mkdir -p $(BUILD) $(TEST) $(SRC) $(LIB)

clean:
	cd $(SRC)/ArrTwoDArray; make clean;
	rm -rf $(BUILD)
	rm -f $(TEST)/*_test
