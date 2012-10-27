#include <iostream>
#include "gtest/gtest.h"
#include <ctime>
#include "TwoDArray.h"

TEST(TwoDArrayTest, Init) {
  TwoDArray<int>* squareMatrixTest = new TwoDArray<int>(3,3,0);
  TwoDArray<int>* rectangleMatrix = new TwoDArray<int>(2,7,5);
  EXPECT_EQ(squareMatrixTest->access(0,1),0);
  EXPECT_EQ(squareMatrixTest->access(2,2),0);
  EXPECT_EQ(rectangleMatrix->access(1,5),5);
  delete squareMatrixTest;
  delete rectangleMatrix;

  TwoDArray<std::string>* strArr = new TwoDArray<std::string>(4,4,"zyx");
  EXPECT_EQ(strArr->access(2,3)[2],'x');
  delete strArr;

  TwoDArray<double>* dblArr = new TwoDArray<double>(10,8,.52);
  EXPECT_EQ(dblArr->access(2,3),.52);
  delete dblArr;
}

TEST(TwoDArrayTest, Access) {
  TwoDArray<int>* sqArr = new TwoDArray<int>(3,3,2);
  EXPECT_EQ(sqArr->access(1,2)&sqArr->access(2,1),2);
  sqArr->insert(0,0,23);
  EXPECT_EQ(sqArr->access(0,0),23);
  sqArr->insert(2,1,4);
  EXPECT_EQ(sqArr->access(2,1),4);

  //should fail/break in runtime (out of bounds):
  //does fail:  sqArr->insert(3,3,5);
  //does fail:  sqArr->access(1,4);

  int randNum = clock()%100;

  sqArr = new TwoDArray<int>(3,3,randNum);
  EXPECT_EQ(sqArr->access(2,2),randNum);
  delete sqArr;

  TwoDArray<double>* rctArr = new TwoDArray<double>(3,9,3.69);
  EXPECT_EQ(rctArr->access(2,8),3.69);
  rctArr->insert(0,0,2.48);
  EXPECT_EQ(rctArr->access(0,0),2.48);
  delete rctArr;

  TwoDArray<std::string>* strArr = new TwoDArray<std::string>(4,2,"moo");
  EXPECT_EQ(strArr->access(2,1)[0],'m');
  EXPECT_EQ(strArr->access(3,0)[1],'o');
  strArr->insert(1,0,"bahh");
  EXPECT_EQ(strArr->access(1,0)[2],'h');
  EXPECT_TRUE(strArr->access(1,0).compare("bahh")==0);
  delete strArr;
}

TEST(TwoDArrayTest, Insert) {
  int randNum = clock()%10;
  TwoDArray<int>* sqArr = new TwoDArray<int>(3,3,randNum);
  EXPECT_EQ(sqArr->access(2,2),randNum);
  for(int i = 0; i<3; i++) {
    sqArr->insert(i,i,randNum*i);
    EXPECT_EQ(sqArr->access(i,i),randNum*i);
  }
  delete sqArr;

  TwoDArray<double>* geoArr = new TwoDArray<double>(3,5,2.0);
  for(int i = 0; i<geoArr->getNumRows(); i++) {
    for(int j = 0; j<geoArr->getNumCols(); j++) {
      for(int iter = i+j; iter>0; --iter) {
        geoArr->insert(i,j,geoArr->access(i,j)/2);
      }
    }
  }
  EXPECT_EQ(geoArr->access(2,1),.25);
  EXPECT_EQ(geoArr->access(2,3),.0625);
  delete geoArr;

  TwoDArray<std::string>* strArr = new TwoDArray<std::string>(4,2,"waitForIt");
  char randChar = clock()%80 + 40;
  std::string test = "";
  test+=randChar;
  test+=(randChar+2);
  test+=(randChar+4);
  test+=(randChar-2);
  test+=(randChar-4);
  EXPECT_TRUE(strArr->access(1,1).compare("waitForIt")==0);
  strArr->insert(1,1,test);
  EXPECT_TRUE(strArr->access(1,1).compare(test)==0);
  EXPECT_FALSE(strArr->access(1,1).compare("waitForIt")==0);
  
  delete strArr;

}

TEST(TwoDArrayTest, Remove) {
  int randNum = clock()%10;
  TwoDArray<int>* sqArr = new TwoDArray<int>(3,3,randNum);
  EXPECT_EQ(sqArr->access(0,2),randNum);
  
  for(int i = 0; i<3; i++) {
    sqArr->insert(i,i,-10);
  }
  EXPECT_FALSE(sqArr->access(2,0)==-10);
  EXPECT_EQ(sqArr->access(2,2),-10);
  sqArr->remove(2,2);
  EXPECT_EQ(sqArr->access(2,2), randNum);
  delete sqArr;

  TwoDArray<double>* dblArr = new TwoDArray<double>(3,9,-0.1324);
  EXPECT_EQ(dblArr->access(1,5),-0.1324);
  dblArr->remove(1,5);

  EXPECT_EQ(dblArr->access(1,5),-0.1324);
  //std::cout<<"No seg fault"<<std::endl;
  dblArr->insert(2,4,3.2);
  dblArr->insert(0,6,2.3);
  std::cout<<"No seg fault"<<std::endl;
  dblArr->insert(1,5,13.42);
  std::cout<<"No seg fault"<<std::endl;
  dblArr->print();
  EXPECT_EQ(dblArr->access(1,5),13.42);
  std::cout<<"No seg fault"<<std::endl;
  EXPECT_EQ(dblArr->access(0,6),2.3);
  std::cout<<"No seg fault"<<std::endl;
  dblArr->remove(0,6);
  std::cout<<"No seg fault"<<std::endl;
  dblArr->remove(1,5);
  std::cout<<"No seg fault"<<std::endl;
  EXPECT_EQ(dblArr->access(0,6),-0.1324);
  std::cout<<"No seg fault"<<std::endl;
  EXPECT_EQ(dblArr->access(1,5),-0.1324);
  std::cout<<"No seg fault"<<std::endl;
  delete dblArr;


  TwoDArray<std::string>* strArr = new TwoDArray<std::string>(4,2,"meow");
  strArr->insert(3,1,"moo");
  EXPECT_TRUE(strArr->access(0,0).compare("meow")==0);
  EXPECT_FALSE(strArr->access(3,1).compare("meow")==0);
  EXPECT_TRUE(strArr->access(3,1).compare("moo")==0);
  strArr->remove(3,1);
  EXPECT_TRUE(strArr->access(3,1).compare("meow")==0);
  delete strArr;
}

TEST(TwoDArrayTest, NumRows) {
  int randNum = clock()%10;
  TwoDArray<int>* sqArr = new TwoDArray<int>(3,3,randNum);
  EXPECT_EQ(sqArr->getNumRows(),3);
  delete sqArr;

  TwoDArray<double>* dblArr = new TwoDArray<double>(randNum*5+2,randNum*5+5,.1234);
  EXPECT_EQ(dblArr->getNumRows(),randNum*5+2);
  EXPECT_FALSE(dblArr->getNumRows()==(randNum*5+5));
  delete dblArr;

  TwoDArray<std::string>* strArr = new TwoDArray<std::string>(4321,56,"qwer");
  EXPECT_EQ(strArr->getNumRows(),4321);
  int oddLength = strArr->getNumRows()*((strArr->access(25,50)).length());
  EXPECT_EQ(oddLength, (4321*4));
  delete strArr;
}

TEST(TwoDArrayTest, NumCols) {
  int randNum = clock()%10;
  TwoDArray<int>* sqArr = new TwoDArray<int>(3,7,randNum);
  EXPECT_EQ(sqArr->getNumCols(),7);
  delete sqArr;

  TwoDArray<double>* dblArr = new TwoDArray<double>(randNum*5+2,randNum*5+5,.1234);
  EXPECT_EQ(dblArr->getNumCols(),randNum*5+5);
  EXPECT_FALSE(dblArr->getNumCols()==(randNum*5));
  delete dblArr;

  TwoDArray<std::string>* strArr = new TwoDArray<std::string>(4321,56,"qwerty");
  int oddLength = strArr->getNumCols()*((strArr->access(25,50)).length());
  EXPECT_EQ(oddLength, (56*6));
  delete strArr;
}
