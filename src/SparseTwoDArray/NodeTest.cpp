#include "Node.h"
#include <iostream>

int main() {
  Node<int>* testA = new Node<int>(0,5);
  std::cout << testA->getValue() << std::endl;
  testA->setNext(new Node<int>(0,12));
  std::cout << testA->getNext()->getValue() << std::endl;
  int* var = new int[10];
  var[0] = 5;
  Node<int>** testB;
  testB = new Node<int>*[10];
  testB[5] = testA;
  std::cout << testB[5]->getValue() << std::endl;
  for(int i = 0; i<10; i++) {
    testB[i] = new Node<int>(0,i);
  }
}
