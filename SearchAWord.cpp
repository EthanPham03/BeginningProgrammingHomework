// A program that compares words from two files
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

bool searchWord(const std::vector<std::string>& words, const std::string& target) {
    for (const auto& word : words) {
        if (word == target) {
            return true;  
        }
    }
    return false;  
}

int main() {
    const int MAX_WORDS = 10000;
    std::vector<std::string> words;
    std::string word;

    // Read the first file and store the words
    std::ifstream inputFile("/Users/ethanpham/Desktop/RandomWords.txt");
    if (!inputFile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    while (words.size() < MAX_WORDS && std::getline(inputFile, word)) {
        words.push_back(word);
    }
    inputFile.close();

    std::ifstream searchFile("/Users/ethanpham/Desktop/SearchWords.txt");
    if (!searchFile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    int foundCount = 0;

    while (std::getline(searchFile, word)) {
        std::istringstream iss(word);
        std::string individualWord;

        while (iss >> individualWord) {
            if (searchWord(words, individualWord)) {
                foundCount++;
            }
        }
    }

    searchFile.close();

    std::cout << "Number of words found: " << foundCount << std::endl;

    return 0;
}
