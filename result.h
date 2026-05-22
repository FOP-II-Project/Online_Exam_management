#ifndef RESULT_H
#define RESULT_H

#include <string>
#include <vector>
using namespace std;

// Result class
class Result {
private:
    string studentId;
    int examId;
    int score;
    int totalMarks;
    char grade;
    bool passed;

public:
    Result();
    Result(string sId, int eId, int sc, int total);
    
    string getStudentId() const;
    int getExamId() const;
    int getScore() const;
    int getTotalMarks() const;
    char getGrade() const;
    bool isPassed() const;
    
    void setStudentId(string sId);
    void setExamId(int eId);
    void setScore(int sc);
    void setTotalMarks(int total);
    void setGrade(char g);
    void setPassed(bool p);
    
    void calculateGrade();
    void displayResult() const;
    float getPercentage() const;
};

typedef Result ResultType;

// Functions using vector (STL)
void displayAllResults(const vector<ResultType> &results);
void displayStudentResults(const vector<ResultType> &results, string studentId);
int searchResult(const vector<ResultType> &results, string studentId, int examId);

#endif
