// A program that sorts a list of integers
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void bubbleSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int MAX_INTEGERS = 100000;
    std::vector<int> integers;
    int number;

    std::ifstream inputFile("/Users/ethanpham/Desktop/ListOfIntegers.txt");
    if (!inputFile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    while (integers.size() < MAX_INTEGERS && inputFile >> number) {
        integers.push_back(number);
    }
    inputFile.close();

    bubbleSort(integers);

    int index;
    std::cout << "Enter an index (0 to " << MAX_INTEGERS - 1 << "): ";
    std::cin >> index;

    // Validate the index
    if (index < 0 || index >= MAX_INTEGERS) {
        std::cerr << "Index out of bounds." << std::endl;
        return 1;
    }

    // Display the integer at the specified index
    std::cout << "The integer at index " << index << " is: " << integers[index] << std::endl;

    return 0;
}
