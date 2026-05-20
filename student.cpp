#include "student.h"
#include "utility.h"
#include <iostream>
using namespace std;

// ============================================================
// FUNCTION: addStudent
// ============================================================
// PURPOSE: Add a new student to the system
// PARAMETERS:
// - students[]: array storing all student records
// - studentCount: current number of students (passed by reference)
// RETURN: void
// LOGIC:
// 1. Check if array is full
// 2. Accept student details from user
// 3. Store in array at index studentCount
// 4. Increment studentCount
// CONCEPTS USED:
// - Arrays of structures
// - Pass by reference
// - Input validation
// - Nested structures (Date)
// WHY NEEDED: Core functionality for admin to register students
// INTERACTION: Called from main menu, data saved by filemanager
// ============================================================
void addStudent(StudentType students[], int &studentCount) {
    clearScreen();
    displayHeader("ADD NEW STUDENT");
    
    if (studentCount >= MAX_STUDENTS) {
        cout << "Error: Maximum student limit reached!" << endl;
        pauseSystem();
        return;
    }
    
    StudentType newStudent;
    
    cout << "Enter Student ID: ";
    cin >> newStudent.studentId;
    cin.ignore();
    
    // Validate student ID is positive
    if (!validatePositiveInt(newStudent.studentId)) {
        cout << "Error: Student ID must be positive!" << endl;
        pauseSystem();
        return;
    }
    
    // Check for duplicate ID
    if (searchStudent(students, studentCount, newStudent.studentId) != -1) {
        cout << "Error: Student ID already exists!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "Enter Full Name: ";
    getline(cin, newStudent.fullName);
    
    // Validate name is not empty
    if (newStudent.fullName.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "Enter Department: ";
    getline(cin, newStudent.department);
    
    // Validate department is not empty
    if (newStudent.department.empty()) {
        cout << "Error: Department cannot be empty!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "Enter Password: ";
    getline(cin, newStudent.password);
    
    // Validate password is not empty
    if (newStudent.password.empty()) {
        cout << "Error: Password cannot be empty!" << endl;
        pauseSystem();
        return;
    }
    
    // Input registration date (nested structure)
    cout << "\n--- Registration Date ---" << endl;
    cout << "Enter Day (1-31): ";
    cin >> newStudent.registrationDate.day;
    
    // Validate day
    if (newStudent.registrationDate.day < 1 || newStudent.registrationDate.day > 31) {
        cout << "Error: Day must be between 1 and 31!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "Enter Month (1-12): ";
    cin >> newStudent.registrationDate.month;
    
    // Validate month
    if (newStudent.registrationDate.month < 1 || newStudent.registrationDate.month > 12) {
        cout << "Error: Month must be between 1 and 12!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "Enter Year: ";
    cin >> newStudent.registrationDate.year;
    
    // Validate year
    if (newStudent.registrationDate.year < 1900 || newStudent.registrationDate.year > 2100) {
        cout << "Error: Year must be between 1900 and 2100!" << endl;
        pauseSystem();
        return;
    }
    
    // Add student to array
    students[studentCount] = newStudent;
    studentCount++;
    
    cout << "\nStudent added successfully!" << endl;
    cout << "Total students: " << studentCount << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: displayStudents
// ============================================================
// PURPOSE: Display all registered students
// PARAMETERS:
// - students[]: array of student records
// - studentCount: number of students to display
// RETURN: void
// LOGIC:
// 1. Check if any students exist
// 2. Loop through array
// 3. Display each student's information
// CONCEPTS USED:
// - Arrays of structures
// - For loop
// - Accessing structure members
// WHY NEEDED: Allows admin to view all students
// INTERACTION: Called from admin menu
// ============================================================
void displayStudents(const StudentType students[], int studentCount) {
    clearScreen();
    displayHeader("ALL STUDENTS");
    
    if (studentCount == 0) {
        cout << "No students registered yet." << endl;
        pauseSystem();
        return;
    }
    
    for (int i = 0; i < studentCount; i++) {
        cout << "\n--- Student " << (i + 1) << " ---" << endl;
        displayStudentInfo(students[i]);
        displayLine();
    }
    
    cout << "\nTotal Students: " << studentCount << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: searchStudent
// ============================================================
// PURPOSE: Search for a student by ID
// PARAMETERS:
// - students[]: array to search
// - studentCount: number of students
// - studentId: ID to search for
// RETURN: index if found, -1 if not found
// LOGIC:
// 1. Loop through student array
// 2. Compare each student's ID with search key
// 3. Return index if match found
// 4. Return -1 if not found
// CONCEPTS USED:
// - Linear search algorithm
// - Arrays of structures
// - For loop
// WHY NEEDED: Required for update, delete, and login operations
// INTERACTION: Used by multiple functions
// ============================================================
int searchStudent(const StudentType students[], int studentCount, int studentId) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentId == studentId) {
            return i;
        }
    }
    return -1;
}

// ============================================================
// FUNCTION: updateStudent
// ============================================================
// PURPOSE: Update existing student information
// PARAMETERS:
// - students[]: array of students
// - studentCount: total number of students
// RETURN: void
// LOGIC:
// 1. Accept student ID to update
// 2. Search for student
// 3. If found, accept new details
// 4. Update the record
// CONCEPTS USED:
// - Arrays of structures
// - Search operation
// - Input validation
// WHY NEEDED: Allows admin to modify student records
// INTERACTION: Called from admin menu
// ============================================================
void updateStudent(StudentType students[], int studentCount) {
    clearScreen();
    displayHeader("UPDATE STUDENT");
    
    if (studentCount == 0) {
        cout << "No students to update." << endl;
        pauseSystem();
        return;
    }
    
    int studentId;
    cout << "Enter Student ID to update: ";
    cin >> studentId;
    cin.ignore();
    
    int index = searchStudent(students, studentCount, studentId);
    
    if (index == -1) {
        cout << "Student not found!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\n--- Current Information ---" << endl;
    displayStudentInfo(students[index]);
    
    cout << "\n--- Enter New Information ---" << endl;
    
    cout << "Enter Full Name: ";
    getline(cin, students[index].fullName);
    
    cout << "Enter Department: ";
    getline(cin, students[index].department);
    
    cout << "Enter Password: ";
    getline(cin, students[index].password);
    
    cout << "\nStudent updated successfully!" << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: deleteStudent
// ============================================================
// PURPOSE: Remove a student from the system
// PARAMETERS:
// - students[]: array of students
// - studentCount: total students (passed by reference)
// RETURN: void
// LOGIC:
// 1. Accept student ID to delete
// 2. Search for student
// 3. If found, shift all elements after it left
// 4. Decrement studentCount
// CONCEPTS USED:
// - Arrays of structures
// - Array manipulation
// - For loop
// WHY NEEDED: Allows admin to remove students
// INTERACTION: Called from admin menu
// ============================================================
void deleteStudent(StudentType students[], int &studentCount) {
    clearScreen();
    displayHeader("DELETE STUDENT");
    
    if (studentCount == 0) {
        cout << "No students to delete." << endl;
        pauseSystem();
        return;
    }
    
    int studentId;
    cout << "Enter Student ID to delete: ";
    cin >> studentId;
    
    int index = searchStudent(students, studentCount, studentId);
    
    if (index == -1) {
        cout << "Student not found!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\n--- Student to Delete ---" << endl;
    displayStudentInfo(students[index]);
    
    char confirm;
    cout << "\nAre you sure you want to delete? (y/n): ";
    cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') {
        // Shift elements left to fill the gap
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "Student deleted successfully!" << endl;
        cout << "Total students: " << studentCount << endl;
    } else {
        cout << "Deletion cancelled." << endl;
    }
    
    pauseSystem();
}

// ============================================================
// FUNCTION: studentLogin
// ============================================================
// PURPOSE: Authenticate student credentials
// PARAMETERS:
// - students[]: array of students
// - studentCount: total students
// - loggedInStudentId: stores ID of logged-in student (by reference)
// RETURN: true if login successful, false otherwise
// LOGIC:
// 1. Accept student ID and password
// 2. Search for student by ID
// 3. Verify password matches
// 4. Store student ID if successful
// CONCEPTS USED:
// - Arrays of structures
// - String comparison
// - Boolean return
// - Pass by reference
// WHY NEEDED: Security - only registered students can take exams
// INTERACTION: Called from main menu
// ============================================================
bool studentLogin(const StudentType students[], int studentCount, int &loggedInStudentId) {
    clearScreen();
    displayHeader("STUDENT LOGIN");
    
    int studentId;
    string password;
    
    cout << "Enter Student ID: ";
    cin >> studentId;
    cin.ignore();
    
    cout << "Enter Password: ";
    getline(cin, password);
    
    int index = searchStudent(students, studentCount, studentId);
    
    if (index != -1 && students[index].password == password) {
        loggedInStudentId = studentId;
        cout << "\nLogin successful!" << endl;
        cout << "Welcome, " << students[index].fullName << "!" << endl;
        pauseSystem();
        return true;
    }
    
    cout << "\nInvalid credentials!" << endl;
    pauseSystem();
    return false;
}

// ============================================================
// FUNCTION: displayStudentInfo
// ============================================================
// PURPOSE: Display detailed information of a single student
// PARAMETERS:
// - student: student record to display
// RETURN: void
// LOGIC: Display all fields of the student structure
// CONCEPTS USED:
// - Structure member access
// - Nested structure access (Date)
// WHY NEEDED: Reusable display function
// INTERACTION: Called by multiple display functions
// ============================================================
void displayStudentInfo(const StudentType &student) {
    cout << "Student ID: " << student.studentId << endl;
    cout << "Name: " << student.fullName << endl;
    cout << "Department: " << student.department << endl;
    cout << "Registration Date: " 
         << student.registrationDate.day << "/"
         << student.registrationDate.month << "/"
         << student.registrationDate.year << endl;
}
