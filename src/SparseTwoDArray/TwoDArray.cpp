#include "TwoDArray.h"
#include <iostream>
#include "assert.h"

template <typename T>
TwoDArray<T>::TwoDArray(int r = 5, int c = 5, T def = T()) {
  assert(r>0 && c>0);
  numRows = r;
  numCols = c;
  defVal = def;
  rows = new Node<T>*[r];
  cols = new Node<T>*[c];
  for(int i = 0; i<numRows; i++) {
    rows[i] = new Node<T>(0,defVal);
  }
  for(int i = 0; i<numCols; i++) {
    cols[i] = new Node<T>(0,defVal);
  }
}

template <typename T>
TwoDArray<T>::~TwoDArray<T>() {
  //TODO
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T value) {
  assert(r>=0 && r<numRows);
  assert(c>=0 && c<numCols);
  Node<T>* toBeAdded = new Node<T>(0,value);
  if(rows[r]->getNext() == 0) {
    rows[r] = toBeAdded;
  }
  else {
    Node<T>* prvRow = rows[r]->getNext();
    while(prvRow->getNext()!=0) { //TODO modify node to hold its own row and column number.  
      prvRow = prvRow->getNext();
    }
    
  }
  if(cols[c]->getNext() == 0) {
    cols[c] = toBeAdded;
  }
  else {

  }
}

template class TwoDArray<int>;
template class TwoDArray<std::string>;
template class TwoDArray<double>;  
