// A program that reads two files and displays questions missed and the exam grade
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

void readAnswers(const string &filename, vector<char> &answers);
int compareAnswers(const vector<char> &correct, const vector<char> &student, vector<int> &missedQuestions);
void displayResults(const vector<char> &correct, const vector<char> &student, const vector<int> &missedQuestions);

int main() {
    string correctFile, studentFile;
    vector<char> correctAnswers;
    vector<char> studentAnswers;
    vector<int> missedQuestions;

    cout << "Enter correct answers file: ";
    cin >> correctFile;
    cout << "Enter student's answers file: ";
    cin >> studentFile;

    readAnswers(correctFile, correctAnswers);
    readAnswers(studentFile, studentAnswers);

    if (correctAnswers.size() != studentAnswers.size()) {
      cout << "The number of ansers in the file do not match."
        return 1;
    }

    int totalMissed = compareAnswers(correctAnswers, studentAnswers, missedQuestions);

    displayResults(correctAnswers, studentAnswers, missedQuestions);

    cout << "Total missed questions: " << totalMissed << endl;

    int totalQuestions = correctAnswers.size();
    int totalCorrect = totalQuestions - totalMissed;
    double percentageCorrect = (static_cast<double>(totalCorrect) / totalQuestions) * 100;

    cout << fixed << setprecision(2);
    cout << "Percentage of questions answered correctly: " << percentageCorrect << "%" << endl;

    if (percentageCorrect >= 70.0) {
        cout << "The student passed the exam." << endl;
    } else {
        cout << "The student failed the exam." << endl;
    }

    return 0;
}

void readAnswers(const string &filename, vector<char> &answers) {
    ifstream file(filename);
    char answer;

    if (!file) {
        cout << "Error opening file: " << filename << endl;
        exit(1);
    }

    while (file >> answer) {
        answers.push_back(answer);
    }

    file.close();
}

int compareAnswers(const vector<char> &correct, const vector<char> &student, vector<int> &missedQuestions) {
    int missed = 0;

    for (size_t i = 0; i < correct.size(); i++) {
        if (correct[i] != student[i]) {
            missedQuestions.push_back(i);
            missed++;
        }
    }

    return missed;
}

void displayResults(const vector<char> &correct, const vector<char> &student, const vector<int> &missedQuestions) {
    cout << "\nQuestions Missed:" << endl;
    cout << setw(10) << "Question" << setw(20) << "Correct Answer" << setw(20) << "Student Answer" << endl;
    cout << "----------------------------------------------------------" << endl;

    for (int question : missedQuestions) {
        cout << setw(10) << question + 1 << setw(20) << correct[question] << setw(20) << student[question] << endl;
    }
}
