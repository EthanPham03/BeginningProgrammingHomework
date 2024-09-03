// A program that computes the total cost of the purchase
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
  dounble quantity, regularPrice, discountCost, totalPrice;
  const double REGULAR_PRICE = 99.00;
  double discount = 0.0;
  
  cout << "Please enter quantity: ";
  cin >> quantity;

  if (quantity >= 10 && quantity <= 19) {
    discount = 0.20;
  } else if (quantity >= 20 && quantity <= 49) {
    discount = 0.30;
  } else if (quantity >= 50 && quantity <= 99) {
    discount = 0.40; 
  } else if (quantity >= 100) {
    discount = 0.50;
  }

  regularPrice = quantity * REGULAR_PRICE;
  discountAmount = regularPrice * discount;
  totalPrice = regularPrice - discountAmount; 

  cout << fixed << setpercision(2); 
  cout << "Your discount is " << static_cast<int>(discount * 100) << "%" << endl;
  cout << "Regular Price: " << setw(8) << regularPrice << endl;
  cout << "Discount: " << setw(8) << discountAmoount << endl;
  cout << "Total Price: " << setw(8) << totalPrice << endl;
  
  return 0;
}
