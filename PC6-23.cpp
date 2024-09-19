// A program that stores a list of all prime numbers from 1 to 100
#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int prime) 
{
  if (prime <= 1)
    return false;
  for (int num = 2; num <= prime / 2; num++) {
    if (prime % num == 0)
      return false;
  }
  return true;  
}

int main() 
{
  int start, end;
  string fileName;

  cout << "Enter starting number: ";
  cin >> start;
  cout << "Enter ending number: ";
  cin >> end;

  if (start > end) {
    cout << "Starting number cannot be greater than ending number.\n";
    return 1;
  }

  cout << "Enter file name: ";
  cin >> fileName;

  ofstream outFile(fileName);
  if (!outFile) {
    cout << "Error opening file" << endl;
    return 1;
  }

  for (int i = start; i <= end; i++) {
    if (isPrime(i)) {
      outfile << i << endl;
    } 
  }

  cout << "Prime numbers listed on " << fileName << endl;

  outFile.close();
  
  return 0;
}
