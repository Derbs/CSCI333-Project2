LIB = ../../lib
BUILD = ../../build
TEST = ../../test

CMP = g++
FLAGS = -Wall -Wextra -Werror

$(BUILD)/ArrTest: TwoDArray.o test.cpp
	$(CMP) -o $@ $^ $(FLAGS)

TwoDArray.o: TwoDArray.cpp TwoDArray.h
	$(CMP) -c $^ $(FLAGS)
	rm *.*.gch

clean:
	rm -f *.o
	rm -f test
