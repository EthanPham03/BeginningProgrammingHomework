// A program that counts the amount of prime numbers in a file
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

int main() {
    ifstream inputFile("Integers.txt"); // Name of the file to read from
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int number;
    int primeCount = 0;

    while (inputFile >> number) {
        if (isPrime(number)) {
            primeCount++;
        }
    }

    inputFile.close();

    cout << "Number of prime numbers in the file: " << primeCount << endl;

    return 0;
}
