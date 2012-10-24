#include "Node.h"
#include <iostream> 
#include "assert.h"

template <typename T>
Node<T>::Node(Node<T>* nxtRow = 0, Node<T>* nxtCol = 0, T val = new T(), int r = 0, int c = 0) {
  assert(r>=-1 && c>=-1);
  row = r;
  col = c;
  nextRow = nxtRow;
  nextCol = nxtCol;
  value = val;
}

template <typename T>
Node<T>::~Node() {

}

template <typename T>
void Node<T>::setNextRow(Node<T>* nxt) {
  nextRow = nxt;
}

template <typename T>
void Node<T>::setNextCol(Node<T>* nxt) {
  nextCol = nxt;
}

template <typename T>
void Node<T>::setRow(int r) {
  assert(r>=0);
  row = r;
}

template <typename T>
void Node<T>::setCol(int c) {
  assert(c>=0);
  col = c;
}

template <typename T>
int Node<T>::getRow() {
  return row;
}

template <typename T>
int Node<T>::getCol() {
  return col;
}

template <typename T>
Node<T>* Node<T>::getNextRow() {
  return nextRow;
}

template <typename T>
Node<T>* Node<T>::getNextCol() {
  return nextCol;
}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;

