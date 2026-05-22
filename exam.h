#ifndef EXAM_H
#define EXAM_H

#include <string>
#include <vector>
using namespace std;

// Exam status enumeration
enum ExamStatus {
    ACTIVE,
    INACTIVE,
    COMPLETED
};

typedef ExamStatus ExamStatusType;

// Question class
class Question {
private:
    int questionId;
    string questionText;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctAnswer;
    int mark;

public:
    Question();
    Question(int id, string text, string a, string b, string c, string d, char ans, int m);
    
    int getQuestionId() const;
    string getQuestionText() const;
    string getOptionA() const;
    string getOptionB() const;
    string getOptionC() const;
    string getOptionD() const;
    char getCorrectAnswer() const;
    int getMark() const;
    
    void setQuestionId(int id);
    void setQuestionText(string text);
    void setOptionA(string a);
    void setOptionB(string b);
    void setOptionC(string c);
    void setOptionD(string d);
    void setCorrectAnswer(char ans);
    void setMark(int m);
    
    void inputQuestionData();
    void displayQuestion() const;
    bool checkAnswer(char answer) const;
};

typedef Question QuestionType;

// Exam class using vector for questions (STL)
class Exam {
private:
    int examId;
    string courseName;
    int durationMinutes;
    vector<QuestionType> questions;  // Using vector instead of array
    ExamStatusType status;

public:
    Exam();
    Exam(int id, string course, int duration);
    
    int getExamId() const;
    string getCourseName() const;
    int getDurationMinutes() const;
    int getTotalQuestions() const;
    ExamStatusType getStatus() const;
    QuestionType getQuestion(int index) const;
    
    void setExamId(int id);
    void setCourseName(string course);
    void setDurationMinutes(int duration);
    void setStatus(ExamStatusType st);
    
    void displayExamDetails() const;
    void addQuestion(QuestionType q);
    bool editQuestion(int questionNum);
    bool deleteQuestion(int questionNum);
    bool isActive() const;
};

typedef Exam ExamType;

// Functions using vector (STL)
void createExam(vector<ExamType> &exams);
void addQuestion(vector<ExamType> &exams);
void editQuestion(vector<ExamType> &exams);
void deleteQuestion(vector<ExamType> &exams);
void updateExam(vector<ExamType> &exams);
void deleteExam(vector<ExamType> &exams);
void displayExams(const vector<ExamType> &exams);
int searchExam(const vector<ExamType> &exams, int examId);
void takeExam(const vector<ExamType> &exams, string studentId, 
              vector<class Result> &results);
void addQuestionsToExam(vector<ExamType> &exams, int examIndex);

#endif
