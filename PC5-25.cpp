// A program that reads a list of names
#include <iostream>
#include <fstream>
#include <string>

int main() 
{
  string file;
  cout << "Enter the file: ";
  getline(cin, file);

  string name;
  string first, last;

  bool NameSet = false;
  while (getline(file, name)) {
        if (!firstNameSet) {
            first = name;
            last = name;
            firstNameSet = true;
        } else {
            if (name < firstName) {
                firstName = name;
            }
            if (name > lastName) {
                lastName = name;
            }
        }
    }

  file.close();

  if (firstNameSet) {
        cout << "First is " << firstName << " and Last is " << lastName << endl;
  }
  
  return 0;
}
