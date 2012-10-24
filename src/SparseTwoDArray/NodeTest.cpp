#include "Node.h"
#include <iostream>

int main() {
  Node<int>* testA = new Node<int>(0,0,5,1,2);
  std::cout << testA->getValue() << std::endl;
  testA->setNextRow(new Node<int>(0,0,12,2,1));
  std::cout << testA->getNextRow()->getValue() << std::endl;
  int* var = new int[10];
  var[0] = 5;
  Node<int>** testB;
  testB = new Node<int>*[10];
  testB[5] = testA;
  std::cout << testB[5]->getValue() << std::endl;
  for(int i = 0; i<10; i++) {
    testB[i] = new Node<int>(0,0,i*i,i,9-i);
  }
  for(int i = 0; i<10; i++) {
    std::cout<<"("<<testB[i]->getRow()<<", "<<testB[i]->getCol()<<") :: "<<testB[i]->getValue()<<std::endl;
  }
}
