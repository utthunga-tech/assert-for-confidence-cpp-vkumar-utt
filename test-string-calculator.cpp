#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "string-calculator.h"

TEST_CASE("Test 1: zero number ") {
  cout << "Test 1 : " <<Add("") 
}

TEST_CASE("Test 2: 1 number ") {
  cout << "Test 1 : " <<Add("1") 
}

TEST_CASE("Test 3: 2 number ") {
  cout << "Test 1 : " <<Add("1,2") 
}

TEST_CASE("Test 4: 3 number with multi delimit") {
  cout << "Test 1 : " <<Add("1\n2,3") 
}
