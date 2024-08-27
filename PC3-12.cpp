//
#include <iostream>
using namespace std;

int main()  
{
  double fahrenheit, celsius;

  cout << "Please input the temperature in Celsius: ";
  cin >> celsius; 

  fahrenheit = ( 9 / 5 ) * celsius + 32; 

  cout << " Temperature in Fahrenheit is: " << fahrenheit << endl;
  return 0; 
}
