#include <iostream>
#include "TwoDArray.h"

using std::cout;
using std::endl;

int main() {
  TwoDArray<int>* test = new TwoDArray<int>(5,3,0);
  test->print();
  test->insert(0,1,100);

  test->insert(2,2,1);
  test->insert(1,2,2);
  test->insert(3,1,3); 
  test->insert(0,0,-5);
  test->print();
  return 0;
}
