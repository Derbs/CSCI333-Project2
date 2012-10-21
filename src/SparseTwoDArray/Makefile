LIB = ../../lib
SRC = ../../src
BUILD = ../../build
TEST = ../../test

COMP = g++
FLAGS = -Wall -Wextra -Werror

test: NodeTest.cpp Node.cpp Node.h
	$(COMP) -o $@ $^ $(FLAGS)

Node.o: Node.cpp Node.h
	$(COMP) -c $< $(FLAGS)

clean:
	rm -f *.o
	rm -f test
