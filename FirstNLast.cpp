#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int main() {
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string word;
    std::string first, last;

    first = std::string(std::numeric_limits<std::string>::max());
    last = std::string(std::numeric_limits<std::string>::min());

    while (file >> word) {
        if (word < first) {
            first = word;
        }
        if (word > last) {
            last = word;
        }
    }

    file.close();

    if (first == std::numeric_limits<std::string>::max() || last == std::numeric_limits<std::string>::min()) {
        std::cout << "No words found in file." << std::endl;
    } else {
        std::cout << "First is " << first << " and Last is " << last << std::endl;
    }

    return 0;
}
