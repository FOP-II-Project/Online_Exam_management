#include "result.h"
#include "utility.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Result class implementation
Result::Result() {
    studentId = "";
    examId = 0;
    score = 0;
    totalMarks = 0;
    grade = 'F';
    passed = false;
}

Result::Result(string sId, int eId, int sc, int total) {
    studentId = sId;
    examId = eId;
    score = sc;
    totalMarks = total;
    calculateGrade();
    passed = (score >= (totalMarks * 0.5));
}

string Result::getStudentId() const { return studentId; }
int Result::getExamId() const { return examId; }
int Result::getScore() const { return score; }
int Result::getTotalMarks() const { return totalMarks; }
char Result::getGrade() const { return grade; }
bool Result::isPassed() const { return passed; }

void Result::setStudentId(string sId) { studentId = sId; }
void Result::setExamId(int eId) { examId = eId; }
void Result::setScore(int sc) { score = sc; }
void Result::setTotalMarks(int total) { totalMarks = total; }
void Result::setGrade(char g) { grade = g; }
void Result::setPassed(bool p) { passed = p; }

float Result::getPercentage() const {
    if (totalMarks == 0) return 0.0f;
    return ((float)score / totalMarks) * 100.0f;
}

void Result::calculateGrade() {
    float percentage = getPercentage();
    
    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = 'B';
    } else if (percentage >= 70) {
        grade = 'C';
    } else if (percentage >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
}

void Result::displayResult() const {
    cout << "Student ID: " << studentId << endl;
    cout << "Exam ID: " << examId << endl;
    cout << "Score: " << score << " / " << totalMarks << endl;
    cout << "Percentage: " << fixed << setprecision(2) << getPercentage() << "%" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Status: " << (passed ? "PASSED" : "FAILED") << endl;
}

// Module-level functions using vector
void displayAllResults(const vector<ResultType> &results) {
    clearScreen();
    displayHeader("ALL RESULTS");
    
    if (results.empty()) {
        cout << "No results available." << endl;
        pauseSystem();
        return;
    }
    
    for (size_t i = 0; i < results.size(); i++) {
        cout << "\n--- Result " << (i + 1) << " ---" << endl;
        results[i].displayResult();
        displayLine();
    }
    
    cout << "\nTotal Results: " << results.size() << endl;
    pauseSystem();
}

void displayStudentResults(const vector<ResultType> &results, string studentId) {
    clearScreen();
    displayHeader("MY RESULTS");
    
    int found = 0;
    
    for (size_t i = 0; i < results.size(); i++) {
        if (results[i].getStudentId() == studentId) {
            cout << "\n--- Result " << (found + 1) << " ---" << endl;
            results[i].displayResult();
            displayLine();
            found++;
        }
    }
    
    if (found == 0) {
        cout << "No results found for your account." << endl;
        cout << "Take an exam to see results here." << endl;
    } else {
        cout << "\nTotal Results: " << found << endl;
    }
    
    pauseSystem();
}

int searchResult(const vector<ResultType> &results, string studentId, int examId) {
    for (size_t i = 0; i < results.size(); i++) {
        if (results[i].getStudentId() == studentId && results[i].getExamId() == examId) {
            return i;
        }
    }
    return -1;
}
