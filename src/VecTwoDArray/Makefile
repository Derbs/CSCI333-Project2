LIB = ../../lib
BUILD = ../../build
TEST = ../../test

CMP = g++
FLAGS = -Wall -Wextra -Werror

$(BUILD)/VecTest: TwoDArray.o test.cpp
	$(CMP) -o $@ $^ $(FLAGS)

TwoDArray.o: TwoDArray.cpp TwoDArray.h
	$(CMP) -c $< $(FLAGS)

clean:
	rm -f *.o
	rm -f test
