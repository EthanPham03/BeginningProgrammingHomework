// A program
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double temp1, temp2;
  int celsius;
  double fahrenheit;

  cout << "Enter a temperature: ";
  cin >> temp1;
  cout >> "Enter another temperature: ";
  cin >> temp2;

  int startTemp = floor(min(temp1, temp2));
  int stopTemp = ceil(max(temp1, temp2));

  cout << setw(10) << "Celsius" << setw(15) << "Fahrenheit" << endl;

  for (celsius = startTemp; celsius <= stopTemp; ++celsius) {
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    cout << setw(10) << celsius << setw(15) << fixed << setprecision(2) << fahrenheit << endl;
  }
  return 0;
}
