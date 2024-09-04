// A program that computes and displays the bank service fees for the month
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double checks, initialBalance, deposit, totalCheckCharge, atmTransaction, atmWithdrawn, finalBalance, realFinalBalance;
  const double monthlyCharge = 10.00; 
  const double overdrawnFee = 20.00;
  double feeUnder400 = 0.0;
  double checkCharge = 0.0; 

  cout << "Please enter balance: ";
  cin >> initialBalance;
  if (initialBalance < 0) {
    cout << "Error: Balance cannot be negative." << endl;
    return 1;
  }

  cout << "Please enter total deposit: ";
  cin >> deposit;

  cout << "Please enter checks entered: ";
  cin >> checks;
  if (checks < 0) {
    cout << "Error: number of checks cannot be negative." << endl;
    return 1;
  }

  cout << "Please enter number of ATM transactions: ";
  cin >> atmTransaction;
  if (atmTransaction < 0) {
    cout << "Error: number of ATM transactions cannot be negative." << endl;
    return 1;
  }

  if (atmTransaction > 0) {
    cout << "Enter the amount withdrawn: ";
    cin >> atmWithdrawn;
    if (atmWithdrawn <= 0) {
      cout << "Error: amount withdrawn must be greater than zero." << endl;
      return 1;
    }
  }

  if (initialBalance < 400.00) {
    feeUnder400 = 15.00;
  } else if (initialBalance >= 400) {
    feeUnder400 = 0.00; 
  }

  if (checks < 20) {
    checkCharge = .10;
  } else if (checks >= 20 && checks <= 39) {
    checkCharge = .08;
  } else if (checks >= 40 && checks <= 59) {
    checkCharge = .06;
  } else if (checks >= 60) {
    checkCharge = .04;
  } else if (checks < 0) {
    cout << "Error: checks less than zero." << endl;
    exit(EXIT_FAILURE);
  }

  totalCheckCharge = checks * checkCharge;
  finalBalance = initialBalance - monthlyCharge - feeUnder400 - totalCheckCharge - atmWithdrawn;

  if (finalbalance < 400) {
    finalBalance = finalBalance - overdrawnFee;
  }

  realFinalBalance = finalBalance + deposit;
  
  cout << fixed << setprecision(2);
  cout << "Initial Balance: " << setw(10) << initialBalance << endl;
  cout << "Monthly Charge: " << setw(10) << monthlyCharge << endl;
  cout << "Number of Checks: " << setw(10) << checks << endl;
  cout << "Check Fee: " << setw(10) << totalCheckCharge << endl;
  cout << " ATM Transactions: " << setw(10) << atmTransactions << endl;
  cout << "ATM amount Withdrawn: " << setw(10) << atmWithdrawn << endl;
  cout << "Balance after fees: " << setw(10) << finalBalance << endl;
  cout << "Overdrawn Fee: " << setw(10) << overdrwaFee << endl;
  cout << "Final Balance: " << setw(10) << realFinalBalance << endl;
  
  if (realFinalBalance < 0) {
    cout << "Account is overdrawn." << endl;
  }
  
  return 0;
}
