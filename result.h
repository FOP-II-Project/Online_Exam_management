#ifndef RESULT_H
#define RESULT_H

#include <string>
using namespace std;

// ============================================================
// MODULE: RESULT
// ============================================================
// RESPONSIBILITIES:
// - Define result data structure
// - Calculate grades based on scores
// - Display student results
// - Manage result records
// 
// CONCEPTS DEMONSTRATED:
// - Structures
// - Arrays of structures
// - Typedef
// - Grade calculation algorithms
// 
// INTERACTION WITH OTHER MODULES:
// - Used by exam.cpp to store exam results
// - Uses utility.h for helper functions
// - Uses filemanager.h for persistence
// 
// WHY MODULARIZATION IS BENEFICIAL:
// - Separates result logic from exam logic
// - Easy to modify grading criteria
// - Reusable result display functions
// - Clear responsibility for result management
// ============================================================

// Maximum number of results
const int MAX_RESULTS = 500;

// ============================================================
// STRUCTURE: Result
// ============================================================
// PURPOSE: Store exam result for a student
// DEMONSTRATES: Structure concept
// FIELDS:
// - studentId: which student took the exam
// - examId: which exam was taken
// - score: marks obtained
// - totalMarks: maximum possible marks
// - grade: letter grade (A, B, C, D, F)
// - passed: whether student passed or failed
// ============================================================
struct Result {
    int studentId;
    int examId;
    int score;
    int totalMarks;
    char grade;
    bool passed;
};

// ============================================================
// TYPEDEF: ResultType
// ============================================================
// PURPOSE: Create alias for Result structure
// DEMONSTRATES: Typedef concept
// ============================================================
typedef Result ResultType;

// Function declarations
char calculateGrade(int score, int totalMarks);
void displayResult(const ResultType &result);
void displayAllResults(const ResultType results[], int resultCount);
void displayStudentResults(const ResultType results[], int resultCount, int studentId);
int searchResult(const ResultType results[], int resultCount, int studentId, int examId);

#endif
