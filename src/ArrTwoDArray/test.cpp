#include "TwoDArray.h"
#include <iostream>

using std::cout;
using std::endl;


int main() {
  TwoDArray<int>* victim = new TwoDArray<int>(5,5,0);
  for(int i = 0; i<5; i++) {
    for(int j = 0; j<5; j++) {
      victim->insert(i,j,i);
    }
  }
  victim->print();
  delete victim;
}
