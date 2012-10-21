#include "Node.h"
#include <iostream> 

template <typename T>
Node<T>::Node(Node* nxt = 0, T val = new T()) {
  next = nxt;
  value = val;
}

template <typename T>
Node<T>::~Node() {

}

template <typename T>
void Node<T>::setNext(Node* nxt) {
  next = nxt;
}

template <typename T>
Node<T>* Node<T>::getNext() {
  return next;
}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;

