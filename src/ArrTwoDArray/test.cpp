#include "TwoDArray.h"
#include <iostream>

using std::cout;
using std::endl;


int main() {
  TwoDArray<int>* victim = new TwoDArray<int>(5,10,0);
  for(int i = 0; i<victim->getNumRows(); i++) {
    for(int j = 0; j<victim->getNumCols(); j++) {
      victim->insert(i,j,i+j);
    }
  }
  victim->print();
  delete victim;
  TwoDArray<std::string>* victim2 = new TwoDArray<std::string>(3,2,"moo");
  victim2->print();
  delete victim2;
  return 0;
}
