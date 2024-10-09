// A program that checks passwords for qualifications
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidPassword(const string& password) {
    if (password.length() < 12)
        return false;

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (int i = 0; i < password.length(); i++) {
        char ch = password[i];
        if (isspace(ch)) return false; 
        if (isupper(ch)) hasUpper = true;
        if (islower(ch)) hasLower = true;
        if (isdigit(ch)) hasDigit = true;
        if (!isalnum(ch)) hasSpecial = true; 
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    string password;
    int validCount = 0, invalidCount = 0;

    cout << "Enter passwords (Ctrl+D to stop):\n";

    while (getline(cin, password)) {
        if (isValidPassword(password))
            validCount++;
        else
            invalidCount++;
    }

    cout << "Number of valid passwords: " << validCount << "\n";
    cout << "Number of invalid passwords: " << invalidCount << "\n";

    return 0;
}
