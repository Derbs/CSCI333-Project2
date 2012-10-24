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
    rows[i] = new Node<T>(0,0,defVal,i,-1);
  }
  for(int i = 0; i<numCols; i++) {
    cols[i] = new Node<T>(0,0,defVal,-1,i);
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
  Node<T>* toBeAdded = new Node<T>(0,0,value,r,c);
  Node<T>* prvNode = rows[r];
  //first, work through the rows.  Remember... we goto the proper row IMMEDIATELY.
  // From there, we're just checking the column value within the row (which is the node's index
  // within the row array, so to speak.  Except it's a sparse array, so we can't directly
  // access it.
  
  //check to see if row has ANYTHING populating it.  If not, EASY.
  if(prvNode->getNextCol() == 0) {
    prvNode->setNextCol(toBeAdded);
  }
  else {  //TODO:If there is stuff populating the row, then go ahead and check the next Node's row..
	  // if the next node is EQUAL OR GREATER THAN THE CURRENT NODE, THEN GO AHEAD AND ADD
	  // the toBeAdded node.  MAKE SURE TO INSERT IT unless row is EQUAL to r.
    Node<T>* curr = prvNode->getNextCol();
    while(curr!=0) {
      if(curr->getCol()==c) {
	Node<T>* temp = curr->getNextRow();
	prvNode->setNextCol(toBeAdded);
	toBeAdded->setNextCol(temp);
	delete curr;
	break;
      }
      else if(curr->getCol()>c) {
	prvNode->setNextCol(toBeAdded);
	toBeAdded->setNextCol(curr);
	break;
      }
      else {
	prvNode = curr;
	curr=curr->getNextCol();
      }
    }
    if(curr==0) {
      prvNode->setNextCol(toBeAdded);
    }
  }

  prvNode = cols[c]; 
  // Next, lets work through the columns.  Again, we should keep in mind we need to use
  // getNextRow() and setNextRow(), because we know which column we're looking at, and the indeces
  // of the column are its rows.
  
  //check to see if col has ANYTHING populating it.  If not, EASY.
  if(prvNode->getNextRow() == 0) {
    prvNode->setNextRow(toBeAdded);
  }
  else {  //TODO:If there is stuff populating the row, then go ahead and check the next Node's row..
	  // if the next node is EQUAL OR GREATER THAN THE CURRENT NODE, THEN GO AHEAD AND ADD
	  // the toBeAdded node.  MAKE SURE TO INSERT IT unless row is EQUAL to r.
    Node<T>* curr = prvNode->getNextRow();
    while(curr!=0) {
      if(curr->getRow()==r) {
	Node<T>* temp = curr->getNextRow();
	toBeAdded->setNextRow(temp);
	prvNode->setNextRow(toBeAdded);
	delete curr;
	break;
      }
      else if(curr->getRow()>r) {
	prvNode->setNextRow(toBeAdded);
	toBeAdded->setNextRow(curr);
	break;
      }
      else {
	prvNode = curr;
	curr=curr->getNextRow();
      }
    }
    if(curr==0) {
      prvNode->setNextRow(toBeAdded);
    }
  }
}

template class TwoDArray<int>;
template class TwoDArray<std::string>;
template class TwoDArray<double>;  
