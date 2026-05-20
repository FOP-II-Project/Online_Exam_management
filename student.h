#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

// ============================================================
// MODULE: STUDENT
// ============================================================
// RESPONSIBILITIES:
// - Define student-related data structures
// - Manage student records (add, display, search, update, delete)
// - Handle student authentication
// 
// CONCEPTS DEMONSTRATED:
// - Structures
// - Nested structures
// - Arrays of structures
// - Typedef
// - User-defined data types
// 
// INTERACTION WITH OTHER MODULES:
// - Used by main.cpp for student management
// - Uses utility.h for helper functions
// - Uses filemanager.h for data persistence
// 
// WHY MODULARIZATION IS BENEFICIAL:
// - Separates student logic from other components
// - Easy to maintain student-related features
// - Can be reused in other projects
// - Clear responsibility boundaries
// ============================================================

// Maximum number of students
const int MAX_STUDENTS = 100;

// ============================================================
// NESTED STRUCTURE: Date
// ============================================================
// PURPOSE: Store date information (day, month, year)
// DEMONSTRATES: Nested structure concept
// USAGE: Used inside Student structure for registration date
// ============================================================
struct Date {
    int day;
    int month;
    int year;
};

// ============================================================
// TYPEDEF: DateType
// ============================================================
// PURPOSE: Create alias for Date structure
// DEMONSTRATES: Typedef concept
// BENEFIT: Shorter, cleaner code
// ============================================================
typedef Date DateType;

// ============================================================
// STRUCTURE: Student
// ============================================================
// PURPOSE: Store complete student information
// DEMONSTRATES: 
// - Structure concept
// - Nested structure (Date inside Student)
// - User-defined data type
// FIELDS:
// - studentId: unique identifier
// - fullName: student's complete name
// - department: academic department
// - password: for login authentication
// - registrationDate: when student was registered (nested structure)
// ============================================================
struct Student {
    int studentId;
    string fullName;
    string department;
    string password;
    DateType registrationDate;  // Nested structure
};

// ============================================================
// TYPEDEF: StudentType
// ============================================================
// PURPOSE: Create alias for Student structure
// DEMONSTRATES: Typedef concept
// ============================================================
typedef Student StudentType;

// Function declarations for student management
void addStudent(StudentType students[], int &studentCount);
void displayStudents(const StudentType students[], int studentCount);
int searchStudent(const StudentType students[], int studentCount, int studentId);
void updateStudent(StudentType students[], int studentCount);
void deleteStudent(StudentType students[], int &studentCount);
bool studentLogin(const StudentType students[], int studentCount, int &loggedInStudentId);
void displayStudentInfo(const StudentType &student);

#endif
