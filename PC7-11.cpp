// A program that reads two files and displays questions missed and the exam grade
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

void readAnswers(const string& fileName, vector<char>& answers);
void compareAnswers(const vector<char>& correct, const vector<char>& student, vector<int>& missedQuestions);
void displayResults(const vector<char>& correct, const vector<char>& student, const vector<int>& missedQuestions);

int main() {
    string correctFile, studentFile;

    cout << "Enter correct answers file: ";
    cin >> correctFile;
    cout << "Enter correct answers file: ";
    cin >> studentFile;

    vector<char> correctAnswers;
    vector<char> studentAnswers;

    readAnswers(correctFile, correctAnswers);
    readAnswers(studentFile, studentAnswers);

    vector<int> missedQuestions;

    compareAnswers(correctAnswers, studentAnswers, missedQuestions);
    displayResults(correctAnswers, studentAnswers, missedQuestions);

    return 0;
}

void readAnswers(const string& fileName, vector<char>& answers) {
    ifstream file(fileName.c_str());
    char answer;
    if (!file) {
        cout << "Error opening file: " << fileName << endl;
        return;
    }
    while (file >> answer) {
        answers.push_back(answer);
    }
    file.close();
}

void compareAnswers(const vector<char>& correct, const vector<char>& student, vector<int>& missedQuestions) {
    for (size_t i = 0; i < correct.size() && i < student.size(); i++) {
        if (correct[i] != student[i]) {
            missedQuestions.push_back(i); 
        }
    }
}

void displayResults(const vector<char>& correct, const vector<char>& student, const vector<int>& missedQuestions) {
    int totalQuestions = correct.size();
    int missedCount = missedQuestions.size();
    int correctCount = totalQuestions - missedCount;
    double correctPercentage = (static_cast<double>(correctCount) / totalQuestions) * 100;

    if (missedCount > 0) {
        cout << "Missed Questions: " << endl;
        cout << "Question\tCorrect Answer\tStudent Answer" << endl;
        for (size_t i = 0; i < missedQuestions.size(); i++) {
            int question = missedQuestions[i];
            cout << setw(8) << question + 1 << "\t" << setw(14) << correct[question] 
                 << "\t" << setw(14) << student[question] << endl;
        }
    } else {
        cout << "No questions missed." << endl;
    }

    cout << "\nTotal Questions Missed: " << missedCount << endl;
    cout << "Percentage Correct: " << fixed << setprecision(2) << correctPercentage << "%" << endl;
    if (correctPercentage >= 70.0) {
        cout << "Exam Passed" << endl;
    } else {
        cout << "Exam Failed" << endl;
    }
}
