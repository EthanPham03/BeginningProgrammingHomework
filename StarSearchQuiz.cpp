// A program that reads a file, drops the highest and lowest value, and averages the rest
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool validateScore(double score);
void calcScore(const vector<double>& scores);
double findLowest(const vector<double>& scores);
double findHighest(const vector<double>& scores);

const double MIN_SCORE = 0.0;
const double MAX_SCORE = 10.0;

int main() {
    vector<double> scores;
    ifstream inputFile("/Users/ethanpham/Desktop/StarSearch.txt");
    double score;

    if (!inputFile) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    while (inputFile >> score) {
        if (validateScore(score)) {
            scores.push_back(score);
        } else {
            cout << "Invalid score ignored. Scores must be between " << MIN_SCORE << " and " << MAX_SCORE << "." << endl;
        }
    }

    inputFile.close();

    if (scores.size() < 3) {
        cerr << "Error: Not enough valid scores to calculate the result. At least 3 scores are required." << endl;
        return 1;
    }

    calcScore(scores);

    return 0;
}

bool validateScore(double score) {
    return (score >= MIN_SCORE && score <= MAX_SCORE);
}

void calcScore(const vector<double>& scores) {
    double lowest = findLowest(scores);
    double highest = findHighest(scores);
    double sum = 0.0;

    for (size_t i = 0; i < scores.size(); i++) {
        sum += scores[i];
    }

    sum = sum - lowest - highest;
    double average = sum / (scores.size() - 2); 

    cout << fixed << setprecision(3);
    cout << "The final score is: " << average << endl;
}

double findLowest(const vector<double>& scores) {
    double lowest = scores[0];

    for (size_t i = 1; i < scores.size(); i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    return lowest;
}

double findHighest(const vector<double>& scores) {
    double highest = scores[0];

    for (size_t i = 1; i < scores.size(); i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }

    return highest;
}
