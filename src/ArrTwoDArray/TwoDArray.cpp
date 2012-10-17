#include <iostream>
#include "TwoDArray.h"

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def) {
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
  
}
template <typename T>
void TwoDArray<T>::insert(int r, int c, T value) {
  theArray[r][c] = value;
}
template <typename T>
T TwoDArray<T>::access(int r, int c) {
  return theArray[r][c];
}
template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  theArray[r][c] = defVal;
}
template <typename T>
void TwoDArray<T>::print() {
  
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
