#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "string-calculator.h"

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
