#include "result.h"
#include "utility.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ============================================================
// FUNCTION: calculateGrade
// ============================================================
// PURPOSE: Calculate letter grade based on percentage
// PARAMETERS:
// - score: marks obtained by student
// - totalMarks: maximum possible marks
// RETURN: char representing grade (A, B, C, D, F)
// LOGIC:
// 1. Calculate percentage
// 2. Apply grading criteria
// 3. Return appropriate grade
// GRADING CRITERIA:
// - 90-100%: A
// - 80-89%: B
// - 70-79%: C
// - 60-69%: D
// - Below 60%: F
// CONCEPTS USED:
// - Arithmetic operations
// - Conditional statements (if-else)
// - Type casting
// WHY NEEDED: Standardized grade calculation
// INTERACTION: Called by takeExam function
// ============================================================
char calculateGrade(int score, int totalMarks) {
    if (totalMarks == 0) {
        return 'F';
    }
    
    float percentage = (float)score / totalMarks * 100;
    
    if (percentage >= 90) {
        return 'A';
    } else if (percentage >= 80) {
        return 'B';
    } else if (percentage >= 70) {
        return 'C';
    } else if (percentage >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// ============================================================
// FUNCTION: displayResult
// ============================================================
// PURPOSE: Display a single result record
// PARAMETERS:
// - result: result record to display
// RETURN: void
// LOGIC:
// 1. Display all result fields
// 2. Calculate and show percentage
// 3. Show pass/fail status
// CONCEPTS USED:
// - Structure member access
// - Arithmetic operations
// - Conditional display
// WHY NEEDED: Formatted result presentation
// INTERACTION: Called after exam completion and by display functions
// ============================================================
void displayResult(const ResultType &result) {
    cout << "Student ID: " << result.studentId << endl;
    cout << "Exam ID: " << result.examId << endl;
    cout << "Score: " << result.score << " / " << result.totalMarks << endl;
    
    // Format percentage to 2 decimal places
    float percentage = (float)result.score / result.totalMarks * 100;
    cout << "Percentage: ";
    cout.precision(2);
    cout << fixed << percentage << "%" << endl;
    cout.unsetf(ios::fixed);
    
    cout << "Grade: " << result.grade << endl;
    cout << "Status: " << (result.passed ? "PASSED" : "FAILED") << endl;
}

// ============================================================
// FUNCTION: displayAllResults
// ============================================================
// PURPOSE: Display all results in the system
// PARAMETERS:
// - results[]: array of result records
// - resultCount: number of results
// RETURN: void
// LOGIC:
// 1. Check if any results exist
// 2. Loop through result array
// 3. Display each result
// CONCEPTS USED:
// - Arrays of structures
// - For loop
// WHY NEEDED: Allows admin to view all exam results
// INTERACTION: Called from admin menu
// ============================================================
void displayAllResults(const ResultType results[], int resultCount) {
    clearScreen();
    displayHeader("ALL RESULTS");
    
    if (resultCount == 0) {
        cout << "No results available." << endl;
        pauseSystem();
        return;
    }
    
    for (int i = 0; i < resultCount; i++) {
        cout << "\n--- Result " << (i + 1) << " ---" << endl;
        displayResult(results[i]);
        displayLine();
    }
    
    cout << "\nTotal Results: " << resultCount << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: displayStudentResults
// ============================================================
// PURPOSE: Display all results for a specific student
// PARAMETERS:
// - results[]: array of results
// - resultCount: total results
// - studentId: ID of student whose results to display
// RETURN: void
// LOGIC:
// 1. Loop through results array
// 2. Display only results matching studentId
// 3. Count and display total results found
// CONCEPTS USED:
// - Arrays of structures
// - Conditional filtering
// - For loop
// WHY NEEDED: Students can view their own results
// INTERACTION: Called from student menu
// ============================================================
void displayStudentResults(const ResultType results[], int resultCount, int studentId) {
    clearScreen();
    displayHeader("MY RESULTS");
    
    int found = 0;
    
    for (int i = 0; i < resultCount; i++) {
        if (results[i].studentId == studentId) {
            cout << "\n--- Result " << (found + 1) << " ---" << endl;
            displayResult(results[i]);
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

// ============================================================
// FUNCTION: searchResult
// ============================================================
// PURPOSE: Search for a specific result by student and exam ID
// PARAMETERS:
// - results[]: array to search
// - resultCount: number of results
// - studentId: student ID to match
// - examId: exam ID to match
// RETURN: index if found, -1 if not found
// LOGIC:
// 1. Loop through results array
// 2. Check if both studentId and examId match
// 3. Return index if found
// CONCEPTS USED:
// - Linear search algorithm
// - Arrays of structures
// - Multiple condition checking
// WHY NEEDED: Prevents duplicate result entries
// INTERACTION: Can be used before creating new result
// ============================================================
int searchResult(const ResultType results[], int resultCount, int studentId, int examId) {
    for (int i = 0; i < resultCount; i++) {
        if (results[i].studentId == studentId && results[i].examId == examId) {
            return i;
        }
    }
    return -1;
}
