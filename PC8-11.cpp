// A program that reads a file and sorts the strings
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 
using namespace std;

int main()
{
    const int NUM_NAMES = 50;
    string names[NUM_NAMES];
    string fileName;
    int actualCout = 0;

    cout << "Enter the file: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < NUM_NAMES; i++)
    {
         if (getline(inputFile, names[i]))
        {
            actualCount++;
        } else {
            break;
        }
    }
    
    inputFile.close(); 

    cout << "\nUnsorted Names:\n";
    for (int i = 0; i < NUM_NAMES; i++)
    {
        cout << names[i] << endl;
    }

    sort(names, names + actualCount);

    cout << "\nSorted Names:\n";
    for (int i = 0; i < actualCount; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}
