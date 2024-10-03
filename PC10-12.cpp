// A program that verifies if a password meets criteria
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool validatePassword(const string& password) 
{
  if (password.length() < 12) {
    cout << "Password must be at least 12 characters long." << endl;
    return false;
  }
  bool hasUpper = false;
  bool hasLower = false;
  bool hasDigit = false;
  bool hasSpecial = false;

  for (int i = 0; i < password.length(); i++) {
        if (isupper(password[i])) hasUpper = true;
        else if (islower(password[i])) hasLower = true;
        else if (isdigit(password[i])) hasDigit = true;
        else if (!isalnum(password[i]) && !isspace(password[i])) hasSpecial = true;
        else if (isspace(password[i])) {
            cout << "Password must not contain spaces.\n";
            return false;
        }
    }
  
    if (!hasUpper) cout << "Password must contain at least one uppercase letter.\n";
    if (!hasLower) cout << "Password must contain at least one lowercase letter.\n";
    if (!hasDigit) cout << "Password must contain at least one digit.\n";
    if (!hasSpecial) cout << "Password must contain at least one special character.\n";

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    string password;

    cout << "Enter your password: ";
    getline(cin, password);

    if (validatePassword(password)) {
        cout << "Password is valid.\n";
    } else {
        cout << "Password is invalid.\n";
    }

    return 0;
}
