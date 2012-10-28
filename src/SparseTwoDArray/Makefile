LIB = ../../lib
SRC = ../../src
BUILD = ../../build
TEST = ../../test

COMP = g++
FLAGS = -Wall -Wextra -Werror

$(BUILD)/SparseTest: ArrTest.cpp TwoDArray.o Node.o
	$(COMP) -o $@ $^ $(FLAGS)

$(BUILD)/Nodetest: NodeTest.cpp Node.cpp Node.h
	$(COMP) -o $@ $^ $(FLAGS)

TwoDArray.o: TwoDArray.cpp TwoDArray.h
	$(COMP) -c $< $(FLAGS)

Node.o: Node.cpp Node.h
	$(COMP) -c $< $(FLAGS)

clean:
	rm -f *.o
	rm -f *test
