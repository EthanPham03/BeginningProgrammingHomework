// A program that calculates a contextant's score using arrays
#include <iostream>
#include <iomanip>
using namespace std;

void getJudgeData(double score[], int size);
bool validateScore(double score);
void calcScore(double scores[], int size);
double findLowest(double scores[], int size);
double findHighest(double scores[], int size);

const double MIN_SCORE = 0;
const double MAX_SCORE = 10;

int main() 
{
    const int numScore = 10; // Change this number to process different number of scores
    double scores[numScore];

    getJudgeData(scores, NUM_SCORES);
    calcScore(scores, NUM_SCORES);

    return 0;
}

void getJudgeData(double scores[], int size) {
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter score for judge " << i + 1 << " (between " << MIN_SCORE << " and " << MAX_SCORE << "): ";
            cin >> scores[i];

            if (!validateScore(scores[i])) {
                cout << "Invalid score. Enter a score between " << MIN_SCORE << " and " << MAX_SCORE << "." << endl;
            }
        } while (!validateScore(scores[i]));
    }
}

bool validateScore(double score) {
    return (score >= MIN_SCORE && score <= MAX_SCORE);
}

void calcScore(double scores[], int size) {
    double lowest = findLowest(scores, size);
    double highest = findHighest(scores, size);
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }

    sum = sum - lowest - highest;  // Subtract the lowest and highest scores
    double average = sum / (size - 2);  // Divide by number of remaining scores after dropping lowest and highest

    cout << fixed << setprecision(2);
    cout << "The final score is: " << average << endl;
}

double findLowest(double scores[], int size) {
    double lowest = scores[0];

    for (int i = 1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    return lowest;
}

double findHighest(double scores[], int size) {
    double highest = scores[0];

    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }

    return highest;
}
