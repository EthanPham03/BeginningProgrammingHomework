// A program that flips a coin and displays the result
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int coinToss() 
{
 return rand() % 2; 
}

int main() 
{
  int tosses, result;
  int num = 0;
  int heads = 0;
  int tails = 0;

  srand(static_cast<unsigned int>(time(0)));

  cout << "Please enter number of tosses: ";
  cin >> tosses;

  for (num < tosses; num++) {
    result = coinToss();

    if (result == 1) {
      cout << "Heads!" << endl;
      heads++;
    } else {
      cout << "Tails!" << endl;
      tails++;
    }
  }
  
  cout << "You got " << heads << " Heads and " << tails << " Tail!" << endl;
  
  return 0;
}
