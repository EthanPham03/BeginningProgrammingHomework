// A program that displays the number of guess on a random number
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateNumber() 
{
  int million = rand() % 1000;
  int thousand = rand() % 1000; 
  int hundred = rand() % 1000;

  return (million * 1000000) + (thousand * 1000) + hundred;
}

int main() 
{
  int number = generateNumber();
  int guess;
  int attempts = 0;

  do {
    cout << "Guess the number (0 - 999,999,999): ";
    cin >> guess;
    attempts++;

    if (guess != target) {
      cout << "Try again\n";
    }
  } while (guess != target);

  cout << "Good Job! Guess attempts: " << attempts << endl;
  
  return 0;
}
