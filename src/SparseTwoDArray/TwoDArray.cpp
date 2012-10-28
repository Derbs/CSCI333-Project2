#include "TwoDArray.h"
#include <iostream>
#include "assert.h"

template <typename T>
TwoDArray<T>::TwoDArray(int r = 5, int c = 5, T def = T()) {
  assert(r>0 && c>0);
  //std::cout<<"There are " << r << " rows and " << c << "columns"<<std::endl;
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
  Node<T>* prv;
  Node<T>* curr;
  if(numRows>numCols) {
    for(int i = 0; i<numRows; i++) {
      curr = rows[i]->getNextCol();
      prv = curr;
      while(curr!=0) {
        prv = curr;
	curr = curr->getNextCol();
	delete prv;
      }
    }
  }
  else {
    for(int i = 0; i<numCols; i++) {
      curr = cols[i]->getNextRow();
      prv = curr;
      while(curr!=0) {
        prv = curr;
	curr = curr->getNextRow();
	delete prv;
      }
    }
  }
  delete[] rows;
  delete[] cols;
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
        //Node<T>* temp = curr;
	prvNode->setNextCol(toBeAdded);
	toBeAdded->setNextCol(curr->getNextCol());
        toBeAdded->setNextRow(curr->getNextRow());
	//delete curr;
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
	//Node<T>* temp = curr;
	//toBeAdded->setNextRow(temp);
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

template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert(r>=0 && r<numRows);
  assert(c>=0 && c<numCols);
  T returnedValue = defVal;
  if(numRows>=numCols) { //if we have more rows than columns, then access row directly, iterate 
			 //through columns.
    Node<T>* curr = rows[r]->getNextCol();
    while(curr!=0 && curr->getCol() <= c) {
      if(curr->getCol() == c) {
	returnedValue = curr->getValue();

	return returnedValue;
      }
      curr = curr->getNextCol();
    }
    
  }
  else {  //if we have more columns than rows, then we access col directly and iterate through rows
    Node<T>* curr = cols[c]->getNextRow();

    while(curr!=0 && curr->getRow() <= r) {
      if(curr->getRow() == r) {
	returnedValue = curr->getValue();

	return returnedValue;
      }
      curr = curr->getNextRow();
    }
  }

  return returnedValue;
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  //we want to do something similar to access, but instead of returning the value, we'll just delete
  //the Node with that row/col identification (if it exists).  If it doesn't exist, we'll do nothing
  assert(r>=0 && r<numRows);
  assert(c>=0 && c<numCols);
  Node<T>* prv = rows[r];
  Node<T>* curr = rows[r]->getNextCol();
  while(curr!=0 && curr->getCol() <= c) {
    if(curr->getCol() == c) {
      prv->setNextCol(curr->getNextCol());	
      break;
    }
    prv = curr;
    curr = curr->getNextCol();
  }

  curr = cols[r]->getNextRow();
  prv = cols[c];
  while(curr!=0 && curr->getRow() <= r) {
    if(curr->getRow() == r) {
      prv->setNextRow(curr->getNextRow());
      break;
    }
    prv = curr;
    curr = curr->getNextRow();
  }
  return;
}



template <typename T>
void TwoDArray<T>::print() {
  std::cout<<"{";
  Node<T>* curr;
  for(int i = 0; i<numRows; i++) {
    curr = rows[i]->getNextCol();

    if(i!=0) std::cout<<" {"; 
    else std::cout<<"{";
    for(int j = 0; j<numCols; j++) {
      if(curr!=0 && j==curr->getCol()) {
	std::cout<<curr->getValue();
	curr = curr->getNextCol();
      }
      else {
	std::cout<<defVal;
      }

      if(j!=numCols-1) {
	std::cout<<", ";
      }
      else {
	std::cout<<"}";
      }
    }
    if(i!=numRows-1) {
      std::cout<<std::endl;
    }
  }
  std::cout<<"}"<<std::endl;
}

template <typename T>
int TwoDArray<T>::getNumRows() {
  return numRows;
}

template <typename T>
int TwoDArray<T>::getNumCols() {
  return numCols;
}

template class TwoDArray<int>;
template class TwoDArray<std::string>;
template class TwoDArray<double>;  
