#include <iostream>
#include "TwoDArray.h"

using std::cout;
using std::endl;

int main() {
  TwoDArray<int>* test = new TwoDArray<int>(5,3,0);
  
  TwoDArray<double>* geoArr = new TwoDArray<double>(3,5,2.0);
  

  geoArr->insert(1,2,.25);

  for(int i = 0; i<3; i++) {

    for(int j = 0; j<5; j++) {
      if(i==1 && j==2) { 
        //do nothing
      }
      else { 
        geoArr->insert(i,j,i+j); 
      }
    }
  }
  geoArr->print();
  for(int i = 0; i<geoArr->getNumRows(); i++) {
    double holder = 2.0;
    for(int j = 0; j<geoArr->getNumCols(); j++) {
      
      geoArr->insert(i,j,holder/2);
      holder = holder/2;
    }
  }
  geoArr->print();
  
  //replicate the print method.
  cout<<"{";
  for(int i = 0; i<geoArr->getNumRows(); i++) {
    cout<<"{";
    for(int j = 0; j<geoArr->getNumCols(); j++) {
      cout<<geoArr->access(i,j)<<", ";
    }
    cout<<"},"<<endl;
  }


  delete test;

  return 0;
}
