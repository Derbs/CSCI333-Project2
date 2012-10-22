#ifndef __TWODARRAY_H_
#define __TWODARRAY_H_

#include <iostream>
#include "Node.h"


template <typename T>
class TwoDArray {
  private:
    int numRows; //number of rows
    int numCols; //number of cols
    Node<T>** rows; //stores pointers to Nodes via rows. Pointer is to first val within row.  
		    //Value, though, is actually the col which that first value exists in.
    Node<T>** cols; //stores pointers to Nodes via columns.  Pointer is to first val within col. 
		    //Value, though, is actually the row which that first value exists in.  
    T defVal;	    //the default value.  Probably won't be used much here.  
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
