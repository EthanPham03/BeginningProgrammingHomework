//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  double totalAmount, sales, stateTax, countyTax, totalTax; 
  string monthYear;
  const double STATE_TAX_RATE = .04;
  const double COUNTY_TAX_RATE = .02; 

  cout << "Please enter the month and year: ";
  cin >> monthYear;

  cout << "Please enter the sales: ";
  cin >> sales;

  stateTax = sales * STATE_TAX_RATE; 
  countyTax = sales * COUNTY_TAX_RATE; 
  totalTax = sales * ( STATE_TAX_RATE + COUNTY_TAX_RATE );
  totalAmount = sales * 1.06; 

  cout << "Month and Year: " << monthYear << endl;
  cout << "--------------------" << endl;

  cout << setw(10) << left << "Total Collected: " << setw(10) << right << totalAmount << endl;
  cout << setw(10) << left << "Sales: " << setw(10) << right << sales << endl;
  cout << setw(10) << left << "County Sales Tax: " << setw(10) << right << countyTax << endl;
  cout << setw(10) << left << "State Sales Tax: " << setw(10) << right << stateTax << endl;
  cout << setw(10) << left << "Total Sales Tax: " << setw(10) << right << totalTax << endl;
  
  return 0;
}
