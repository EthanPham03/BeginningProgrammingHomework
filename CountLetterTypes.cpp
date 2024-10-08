#include <iostream>
#include <fstream>
#include <cctype> 

using namespace std;

int main() {
    ifstream inputFile("/Users/ethanpham/Desktop/RandomWords.txt"); 
    string line;
    int upperCaseCount = 0;

    if (!inputFile) {
        cerr << "Unable to open file." << endl;
        return 1; 
    }

    while (getline(inputFile, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (isupper(line[i])) {
                upperCaseCount++;
            }
        }
    }

    inputFile.close(); 

    cout << "Total number of uppercase letters: " << upperCaseCount << endl;

    return 0; 
}
