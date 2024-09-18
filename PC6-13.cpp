// A program that calculates the average number of days a company's employees are absent
#include <iostream>
#include <iomanip>
using namespace std;

int getEmployees()
{
  int employees;
  do {
    cout << "Number of Employees: ";
    cin >> employees;
    if (employees < 1) {
      cout << "Number of employees must be at at least 1.\n";
    }
  } while (employees < 1);
  return employees;
}

int getDaysAbsent(int employees) 
{
  int daysAbsent = 0, days;
  for (int num = 1; num <= employees; num++) {
    do {
      cout << "Days Out for Employee " << num << ":";
      cin >> days; 
      if (days < 0) {
        cout << "Days cannot be negative.\n";
      }
    } while (days < 0);
    daysAbsent += days;
  }
  return daysAbsent; 
}

double calcAverageDays(int employees, int daysAbsent) {
  return static_cast<double>(daysAbsent) / employees;
}

int main()
{
  int employees = getEmployees();
  int daysAbsent = getDaysAbsent();
  double averageDays = calcAverageDays(employees, daysAbsent);

  cout << fixed << setprecision(2);
  cout << "Average number of days absent is " << averageDays << endl;
  
  return 0;
}
