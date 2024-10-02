// A program that reverses a given string
#include <iostream>
#include <string>
using namespace std;

string reverseString(string);

int main() {
    string inputString;
  
    cout << "Enter a string: ";
    getline(cin, inputString);

    string reversedString = reverseString(inputString);

    cout << "Reversed string: " << reversedString << endl;

    return 0;
}

string reverseString(string str) {
    string reversedStr;
  
    for (int i = str.length() - 1; i >= 0; --i) {
        reversedStr += str[i];
    }
    
    return reversedStr;
}
