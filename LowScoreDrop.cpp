// A program that will process a number of floating-point scores from a file
#include <iostream>
#include <fstream>
#include <limits> // For numeric limits

using namespace std;

int main() {
    ifstream inputFile("/Users/ethanpham/Desktop/RandomDouble.txt"); // Name of the file to read from
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    float score;
    float lowestScore = numeric_limits<float>::max(); // Initialize to the maximum possible float value
    float totalSum = 0.0;
    int count = 0;

    while (inputFile >> score) {
        if (score < lowestScore) {
            lowestScore = score;
        }
        totalSum += score;
        count++;
    }

    inputFile.close();

    if (count <= 1) {
        // If there's 1 or fewer scores, we can't drop the lowest score or calculate an average.
        cerr << "Not enough scores to drop the lowest one and calculate an average." << endl;
        return 1;
    }

    // Calculate the average after dropping the lowest score
    float average = (totalSum - lowestScore) / (count - 1);

    cout << "Average after dropping the lowest score: " << average << endl;

    return 0;
}
