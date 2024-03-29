#include <iostream>
#include "TwoDArray.h"
#include <vector>
#include "assert.h"
using std::vector;
template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
  assert(r>0);
  assert(c>0);
  rows = r;
  cols = c;
  defVal = def;
  theArray = vector< vector<T> >(rows, vector<T>(cols,def));
}

template <typename T>
TwoDArray<T>::~TwoDArray<T>() {
  //The vector may be made on the stack, but almost all of its internal stuff stays on the heap.
  //still, we can do this:
  for(int i = 0; i<rows; i++) {
    theArray[i].clear();
  }
  theArray.clear();
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T value) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<cols);
  theArray[r][c] = value;  
}
template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<cols);
  return theArray[r][c];
}
template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<cols);
  theArray[r][c] = defVal;
}
template <typename T>
void TwoDArray<T>::print() {
  std::cout<<"{";
  for(int i = 0; i<rows; i++) {
    std::cout<<"[";
    for(int j = 0; j<cols; j++) {
      if(j!=cols-1) {
        std::cout<<theArray[i][j]<<", ";
      }
      else {
        std::cout<<theArray[i][j]<<"]";
      }
    }
    if(i!=rows-1) {
      std::cout<<std::endl<<" ";
    }
    else {
      std::cout<<"}"<<std::endl;
    }
  }
}
template <typename T>
int TwoDArray<T>::getNumRows() {
  return rows;
}
template <typename T>
int TwoDArray<T>::getNumCols() {
  return cols;
}

template class TwoDArray<int>;
template class TwoDArray<double>;
template class TwoDArray<std::string>;

