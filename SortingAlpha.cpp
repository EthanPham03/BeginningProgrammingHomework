// A program that reads a file, sorts the words, and display a word at a given index
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_WORDS = 1262;

int main() {
    string words[MAX_WORDS];
    int wordCount = 0;

    ifstream inputFile("/Users/ethanpham/Desktop/MixedCaseWords.txt");
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (wordCount < MAX_WORDS && getline(inputFile, words[wordCount])) {
        wordCount++;
    }
    inputFile.close();

    sort(words, words + wordCount, [](const string &a, const string &b) {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
                                       [](char a, char b) { return tolower(a) < tolower(b); });
    });

    int index;
    cout << "Enter an index (0 to " << wordCount - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= wordCount) {
        cerr << "Invalid index." << endl;
        return 1;
    }

    cout << "The word at index " << index << " is: " << words[index] << endl;

    return 0;
}
