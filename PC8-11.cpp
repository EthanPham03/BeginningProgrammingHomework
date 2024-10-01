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

    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cout << "Error opening file " << fileName << endl;
        return 1;
    }

    for (int i = 0; i < NUM_NAMES; i++)
    {
        getline(inputFile, names[i]);
    }
    
    inputFile.close(); 

    cout << "\nUnsorted Names:\n";
    for (int i = 0; i < NUM_NAMES; i++)
    {
        cout << names[i] << endl;
    }

    sort(names, names + NUM_NAMES);

    cout << "\nSorted Names:\n";
    for (int i = 0; i < NUM_NAMES; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}
