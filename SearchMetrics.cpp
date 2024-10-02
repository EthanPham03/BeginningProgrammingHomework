#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int sequentialSearch(const std::vector<int>& arr, int target) {
    int comparisons = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        comparisons++;
        if (arr[i] == target) {
            return comparisons;
        }
    }
    return comparisons;
}

int binarySearch(const std::vector<int>& arr, int target) {
    int comparisons = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2; 
        if (arr[mid] == target) {
            return comparisons; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return comparisons; 
}

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
    std::string filename;

    std::cout << "Enter the filename containing 100,000 unsorted integers: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    while (integers.size() < MAX_INTEGERS && inputFile >> number) {
        integers.push_back(number);
    }
    inputFile.close();

    int searchItem;
    std::cout << "Enter an integer to search for: ";
    std::cin >> searchItem;

    int seqComparisons = sequentialSearch(integers, searchItem);
    std::cout << "Sequential search comparisons: " << seqComparisons << std::endl;

    bubbleSort(integers);
    std::cout << "Sorting completed. Please wait...\n";

    int binComparisons = binarySearch(integers, searchItem);
    std::cout << "Binary search comparisons: " << binComparisons << std::endl;

    return 0;
}
