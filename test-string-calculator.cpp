#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "string-calculator.h"
#include <assert.h>

TEST_CASE("Test 1: zero number ") {
  cout << "Test 1 : " <<Add("")<<"\n"; 
}

TEST_CASE("Test 2: 1 number ") {
  cout << "Test 2 : " <<Add("1") <<"\n"; 
}

TEST_CASE("Test 3: 2 number ") {
  cout << "Test 3 : " <<Add("1,2") <<"\n"; 
}

TEST_CASE("Test 4: 3 number with multi delimit") {
  cout << "Test 4 : " <<Add("1\n2,3") <<"\n"; 
}

TEST_CASE("Test 5: one negative num and 3 number with multi delimit") {
  cout << "Test 5 : " <<Add("-8,1\n2,3") <<"\n"; 
}

TEST_CASE("Test 6: 2 negative num and 3 number with multi delimit") {
  cout << "Test 6 : " <<Add("-8,1\n2,-5,3") <<"\n"; 
}

TEST_CASE("Test 7: one num>1000 and 3 number with multi delimit") {
  cout << "Test 7 : " <<Add("1\n2,3,1001") <<"\n"; 
}
TEST_CASE("Test 8: 2 num>1000 and 3 number with multi delimit") {
  cout << "Test 8 : " <<Add("1003,1\n2,3,1001") <<"\n"; 
}


TEST_CASE("Test : with delimeter ") {
  int r9 = Add("//;\n1;2");
  assert(r9==3);
}

TEST_CASE("Test 10: with delimeter ") {
  int r10 = Add("//[***]\n1***2***3");
  assert(r10==6);
}

TEST_CASE("Test 11: with multi delimeter ") {
  int r11 = Add("//[*][%]\n1*2%3");
  assert(r11==6);
}

/*TEST_CASE("Test 12: with delimeter with any lenghth") {
  int r12 = Add("///[][%%]\n12%%3");
  assert(r12==6);
}*/
