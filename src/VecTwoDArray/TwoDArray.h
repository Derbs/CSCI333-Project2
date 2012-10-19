#ifndef __TWODARRAY_H_
#define __TWODARRAY_H_

#include <iostream>
#include <vector>
using std::vector;

template <typename T>
class TwoDArray {
  private:
    vector< vector<T> > theArray;
    int rows;
    int cols;
    T defVal;
  public:
    TwoDArray<T>(int r, int c, T def);
    ~TwoDArray<T>();
    void insert(int r, int c, T value);
    T access(int r, int c);
    void remove(int r, int c);
    void print();
    int getNumRows();
    int getNumCols();
};

#endif
