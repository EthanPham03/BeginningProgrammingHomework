// A program that displays the charges for package weight and shipping
#include <iostream>
using namespace std;

int main() 
{
  double weight, distance, charge, finalCharge;
  int rate;

  cout << "Please enter weight in kg: ";
  cin >> weight;

  cout << "Please enter distance shipped in miles: ";
  cin >> distance; 

  if (weight <= 2) {
    charge = 1.10;
  } else if (weight > 2 && weight <= 6) {
    charge = 2.20;
  } else if (weight > 6 && weight <= 10) {
    charge = 3.70;
  } else if (weight > 10 && weight <=20) {
    charge = 4.80;
  } else if (weight <= 0 && weight > 20) {
    cout << "Weight is not valid.";
  }

  if (distance < 0) {
    cout << "Setting distance to 500 miles.";
    distance = 500;
  } else if (distance < 500) {
    distance = 500;
  }

  finalCharge = ((distance + 499) / 500) * charge;
  
  return 0;
}
