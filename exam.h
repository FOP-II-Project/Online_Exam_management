#ifndef EXAM_H
#define EXAM_H

#include <string>
using namespace std;

// ============================================================
// MODULE: EXAM
// ============================================================
// RESPONSIBILITIES:
// - Define exam and question data structures
// - Manage exam creation and question addition
// - Handle exam display
// - Manage exam taking process
// 
// CONCEPTS DEMONSTRATED:
// - Structures
// - Arrays of structures
// - Nested arrays (questions inside exam)
// - Typedef
// - Enum
// 
// INTERACTION WITH OTHER MODULES:
// - Used by main.cpp for exam management
// - Uses utility.h for helper functions
// - Interacts with result.h for score calculation
// - Uses filemanager.h for persistence
// 
// WHY MODULARIZATION IS BENEFICIAL:
// - Separates exam logic from student management
// - Easy to add new exam features
// - Clear separation of concerns
// - Reusable in other educational systems
// ============================================================

// Constants
const int MAX_EXAMS = 50;
const int MAX_QUESTIONS_PER_EXAM = 50;

// ============================================================
// ENUM: ExamStatus
// ============================================================
// PURPOSE: Represent the status of an exam
// DEMONSTRATES: Enum concept
// VALUES:
// - ACTIVE: Exam is available for students
// - INACTIVE: Exam is not available
// - COMPLETED: Exam period has ended
// BENEFIT: Type-safe status representation
// ============================================================
enum ExamStatus {
    ACTIVE,
    INACTIVE,
    COMPLETED
};

// ============================================================
// TYPEDEF: ExamStatusType
// ============================================================
// PURPOSE: Create alias for ExamStatus enum
// DEMONSTRATES: Typedef with enum
// ============================================================
typedef ExamStatus ExamStatusType;

// ============================================================
// STRUCTURE: Question
// ============================================================
// PURPOSE: Store a single multiple-choice question
// DEMONSTRATES: Structure concept
// FIELDS:
// - questionId: unique identifier
// - questionText: the actual question
// - optionA, optionB, optionC, optionD: four choices
// - correctAnswer: correct option ('A', 'B', 'C', or 'D')
// - mark: points awarded for correct answer
// ============================================================
struct Question {
    int questionId;
    string questionText;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctAnswer;
    int mark;
};

// ============================================================
// TYPEDEF: QuestionType
// ============================================================
typedef Question QuestionType;

// ============================================================
// STRUCTURE: Exam
// ============================================================
// PURPOSE: Store complete exam information
// DEMONSTRATES:
// - Structure concept
// - Array inside structure (questions array)
// - Nested data structures
// FIELDS:
// - examId: unique identifier
// - courseName: subject/course name
// - durationMinutes: time limit
// - totalQuestions: number of questions in exam
// - questions[]: array of Question structures
// - status: exam availability status (enum)
// ============================================================
struct Exam {
    int examId;
    string courseName;
    int durationMinutes;
    int totalQuestions;
    QuestionType questions[MAX_QUESTIONS_PER_EXAM];  // Array of structures
    ExamStatusType status;
};

// ============================================================
// TYPEDEF: ExamType
// ============================================================
typedef Exam ExamType;

// Function declarations
void createExam(ExamType exams[], int &examCount);
void addQuestion(ExamType exams[], int examCount);
void editQuestion(ExamType exams[], int examCount);
void deleteQuestion(ExamType exams[], int examCount);
void updateExam(ExamType exams[], int examCount);
void deleteExam(ExamType exams[], int &examCount);
void displayExams(const ExamType exams[], int examCount);
void displayExamDetails(const ExamType &exam);
int searchExam(const ExamType exams[], int examCount, int examId);
void takeExam(const ExamType exams[], int examCount, int studentId, 
              struct Result results[], int &resultCount);

#endif
