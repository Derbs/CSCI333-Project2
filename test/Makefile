SRC = ../src
LIB = ../lib
SLIB = ../../lib
BUILD = ../build
TEST = ../test
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

COMP = g++
FLAGS = -Wall -Wextra -Werror

all:



ArrayBased_test: TwoDArrayTest.cpp TwoDArray.o $(GTEST_MAINA)
	$(COMP) $(FLAGS) $(GTEST_INCLUDES) -pthread -o $@ $^

VecBased_test: TwoDArrayTest.cpp TwoDArray.o $(GTEST_MAINA)
	$(COMP) $(FLAGS) $(GTEST_INCLUDES) -pthread -o $@ $^
LinkBased_test: TwoDArrayTest.cpp TwoDArray.o $(GTEST_MAINA)
	$(COMP) $(FLAGS) $(GTEST_INCLUDES) -pthread -o $@ $^
$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make
clean:
	rm -f *Based
	rm -f $(GTEST_MAINA)
	cd $(GTEST)/make; $(MAKE) clean
