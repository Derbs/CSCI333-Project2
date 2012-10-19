#include <iostream>
#include "TwoDArray.h"
#include "assert.h"

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
  assert(r > 0);
  assert(c > 0);
  rows = r;
  cols = c;
  theArray = new T*[rows];
  defVal = def;
  for(int i = 0; i<rows; i++) {
    theArray[i] = new T[cols];
    for(int j = 0; j<cols; j++) {
      theArray[i][j] = defVal;
    }
  }
}

template <typename T>
TwoDArray<T>::~TwoDArray<T>() {
  for(int i = 0; i<rows; i++) {
    delete[] theArray[i];
  }
  delete[] theArray;
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T value) {
  assert(r>=0&&r<rows && c>=0&&c<cols);
  theArray[r][c] = value;
}
template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert(r>=0&&r<rows && c>=0&&c<cols);
  return theArray[r][c];
}
template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  assert(r>=0 && r<rows && c>=0 && c<cols);
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
