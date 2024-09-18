// A program that averages a group of test scores
#include <iostream>
#include <iomanip>
using namespace std;

void getScore(double &score);
bool validateScore(double score);
void calcAverage(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);

const double MIN_SCORE = 0;
const double MAX_SCORE = 100;

int main() 
{
  double score1, score2, score3, score4, score5;

  getScore(score1);
  getScore(score2);
  getScore(score3);
  getScore(score4);
  getScore(score5);

  calcAverage(score1, score2, score3, score4, score5);

  return 0;
}

void getScore(double &score) {
    do {
        cout << "Enter a test score (between " << MIN_SCORE << " and " << MAX_SCORE << "): ";
        cin >> score;

        if (!validateScore(score)) {
            cout << "Invalid score. Enter a score between " << MIN_SCORE << " and " << MAX_SCORE << "." << endl;
        }
    } while (!validateScore(score));
}

bool validateScore(double score) {
    return (score >= MIN_SCORE && score <= MAX_SCORE);
}

void calcAverage(double score1, double score2, double score3, double score4, double score5) {
    double lowest = findLowest(score1, score2, score3, score4, score5);
  
    double sum = score1 + score2 + score3 + score4 + score5 - lowest;

    double average = sum / 4;
    cout << fixed << setprecision(2);
    cout << "The average of the four scores is: " << average << endl;
}

double findLowest(double score1, double score2, double score3, double score4, double score5) {
    double lowest = score1;

    if (score2 < lowest) lowest = score2;
    if (score3 < lowest) lowest = score3;
    if (score4 < lowest) lowest = score4;
    if (score5 < lowest) lowest = score5;

    return lowest;
}
