// Ethan Pham
// A C++ program to calculate miles per gallon
#include <iostream>

int main() {
  double miles, gallons, mpg;
  std::cout << "Enter miles traveled: ";
  std::cin >> miles; 
  std::cout << "Enter gallons of gas: ";
  std::cin >> gallons;

  if (gallons !=0) {
    mpg = miles / gallons;
    std::cout << "Miles per gallon: " << mpg << std:endl;
  }

  return 0;
}
