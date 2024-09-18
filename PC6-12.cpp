// A program that calculates a contestant's score
#include <iostream>
#include <iomanip>
using namespace std;

void getJudgeData(double &score);
bool validateScore(double score);
void calcScore(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);

const double MIN_SCORE = 0;
const double MAX_SCORE = 10;

int main() 
{
  double score1, score2, score3, score4, score5;

  getJudgeData(score1);
  getJudgeData(score2);
  getJudgeData(score3);
  getJudgeData(score4);
  getJudgeData(score5);

  calcScore(score1, score2, score3, score4, score5);

  return 0;
}

void getJudgeData(double &score) {
    do {
        cout << "Enter a judge score (between " << MIN_SCORE << " and " << MAX_SCORE << "): ";
        cin >> score;

        if (!validateScore(score)) {
            cout << "Invalid score. Enter a score between " << MIN_SCORE << " and " << MAX_SCORE << "." << endl;
        }
    } while (!validateScore(score));
}

bool validateScore(double score) {
    return (score >= MIN_SCORE && score <= MAX_SCORE);
}

void calcScore(double score1, double score2, double score3, double score4, double score5) {
    double lowest = findLowest(score1, score2, score3, score4, score5);
    double highest = findHighest(score1, score2, score3, score4, score5);
    double sum = score1 + score2 + score3 + score4 + score5 - lowest - highest;
    double average = sum / 3;

    cout << fixed << setprecision(2);
    cout << "The final score is: " << average << endl;
}

double findLowest(double score1, double score2, double score3, double score4, double score5) {
    double lowest = score1;

    if (score2 < lowest) lowest = score2;
    if (score3 < lowest) lowest = score3;
    if (score4 < lowest) lowest = score4;
    if (score5 < lowest) lowest = score5;

    return lowest;
}

double findHighest(double score1, double score2, double score3, double score4, double score5) {
    double highest = score1;

    if (score2 > highest) highest = score2;
    if (score3 > highest) highest = score3;
    if (score4 > highest) highest = score4;
    if (score5 > highest) highest = score5;

    return highest;
}
