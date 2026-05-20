#include <iostream>
#include "student.h"
#include "exam.h"
#include "result.h"
#include "filemanager.h"
#include "utility.h"

using namespace std;

// ============================================================
// ONLINE EXAM MANAGEMENT SYSTEM
// ============================================================
// A complete console-based examination management system
// demonstrating modular programming and C++ fundamentals
// 
// CONCEPTS DEMONSTRATED:
// 1. Modular Programming - separate .h and .cpp files
// 2. Structures - Student, Exam, Question, Result, Date
// 3. Nested Structures - Date inside Student
// 4. Arrays of Structures - students[], exams[], results[]
// 5. User-Defined Data Types - custom structures
// 6. Template Functions - swapData, displayValue, searchRecord
// 7. File Handling - save/load from text files
// 8. Functions - modular function design
// 9. Loops - for, while, do-while
// 10. Menu-Driven Programming - main, admin, student menus
// 11. Enum - ExamStatus
// 12. Typedef - type aliases for structures
// ============================================================

// ============================================================
// ENUM: UserRole
// ============================================================
// PURPOSE: Represent different types of users
// DEMONSTRATES: Enum concept
// VALUES:
// - ADMIN: System administrator
// - STUDENT: Regular student user
// BENEFIT: Type-safe user role representation
// ============================================================
enum UserRole {
    ADMIN = 1,
    STUDENT = 2
};

// Global arrays to store data
StudentType students[MAX_STUDENTS];
ExamType exams[MAX_EXAMS];
ResultType results[MAX_RESULTS];

// Counters for array elements
int studentCount = 0;
int examCount = 0;
int resultCount = 0;

// Function declarations
void displayMainMenu();
void displayAdminMenu();
void displayStudentMenu();
bool adminLogin();
void adminPanel();
void studentPanel(int studentId);

// ============================================================
// FUNCTION: main
// ============================================================
// PURPOSE: Entry point of the program
// PARAMETERS: None
// RETURN: int (0 for success)
// LOGIC:
// 1. Load all data from files
// 2. Display main menu
// 3. Handle user choice (Admin/Student/Exit)
// 4. Save all data before exit
// CONCEPTS USED:
// - Do-while loop for menu
// - Switch statement for choices
// - Function calls
// - File handling
// WHY NEEDED: Coordinates entire program flow
// INTERACTION: Calls all major modules
// ============================================================
int main() {
    // Load data from files at startup
    cout << "Loading data..." << endl;
    displayLine();
    loadStudentsFromFile(students, studentCount);
    loadExamsFromFile(exams, examCount);
    loadResultsFromFile(results, resultCount);
    displayLine();
    pauseSystem();
    
    int choice;
    
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        if (!validateChoice(choice, 1, 3)) {
            cout << "Invalid choice! Please try again." << endl;
            pauseSystem();
            continue;
        }
        
        switch (choice) {
            case ADMIN:
                if (adminLogin()) {
                    adminPanel();
                }
                break;
                
            case STUDENT: {
                int loggedInStudentId;
                if (studentLogin(students, studentCount, loggedInStudentId)) {
                    studentPanel(loggedInStudentId);
                }
                break;
            }
            
            case 3:
                cout << "\nSaving data..." << endl;
                displayLine();
                saveStudentsToFile(students, studentCount);
                saveExamsToFile(exams, examCount);
                saveResultsToFile(results, resultCount);
                displayLine();
                cout << "\nThank you for using Online Exam Management System!" << endl;
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}

// ============================================================
// FUNCTION: displayMainMenu
// ============================================================
// PURPOSE: Display the main menu options
// PARAMETERS: None
// RETURN: void
// LOGIC: Display formatted menu with options
// CONCEPTS USED:
// - Output formatting
// - Menu design
// WHY NEEDED: User interface for role selection
// INTERACTION: Called by main function
// ============================================================
void displayMainMenu() {
    clearScreen();
    displayHeader("ONLINE EXAM MANAGEMENT SYSTEM");
    cout << "\n1. Admin Login" << endl;
    cout << "2. Student Login" << endl;
    cout << "3. Exit" << endl;
    displayLine();
}

// ============================================================
// FUNCTION: adminLogin
// ============================================================
// PURPOSE: Authenticate admin credentials
// PARAMETERS: None
// RETURN: true if login successful, false otherwise
// LOGIC:
// 1. Accept username and password
// 2. Compare with hardcoded credentials
// 3. Return result
// CONCEPTS USED:
// - String comparison
// - Boolean return
// - Input handling
// WHY NEEDED: Security - only authorized admin can manage system
// INTERACTION: Called from main menu
// NOTE: In real system, credentials would be in database
// ============================================================
bool adminLogin() {
    clearScreen();
    displayHeader("ADMIN LOGIN");
    
    string username, password;
    
    cout << "Enter Username: ";
    getline(cin, username);
    
    cout << "Enter Password: ";
    getline(cin, password);
    
    // Hardcoded admin credentials for simplicity
    if (username == "admin" && password == "admin123") {
        cout << "\nLogin successful!" << endl;
        cout << "Welcome, Administrator!" << endl;
        pauseSystem();
        return true;
    }
    
    cout << "\nInvalid credentials!" << endl;
    pauseSystem();
    return false;
}

// ============================================================
// FUNCTION: displayAdminMenu
// ============================================================
// PURPOSE: Display admin menu options
// PARAMETERS: None
// RETURN: void
// LOGIC: Display all admin functionalities
// CONCEPTS USED:
// - Output formatting
// - Menu design
// WHY NEEDED: Admin interface for system management
// INTERACTION: Called by adminPanel
// ============================================================
void displayAdminMenu() {
    clearScreen();
    displayHeader("ADMIN PANEL");
    cout << "\n--- Student Management ---" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Update Student" << endl;
    cout << "5. Delete Student" << endl;
    
    cout << "\n--- Exam Management ---" << endl;
    cout << "6. Create Exam" << endl;
    cout << "7. Add Question to Exam" << endl;
    cout << "8. Edit Question" << endl;
    cout << "9. Delete Question" << endl;
    cout << "10. Update Exam" << endl;
    cout << "11. Delete Exam" << endl;
    cout << "12. Display All Exams" << endl;
    
    cout << "\n--- Result Management ---" << endl;
    cout << "13. View All Results" << endl;
    
    cout << "\n--- System ---" << endl;
    cout << "14. Save Data" << endl;
    cout << "15. Logout" << endl;
    displayLine();
}

// ============================================================
// FUNCTION: adminPanel
// ============================================================
// PURPOSE: Handle admin operations
// PARAMETERS: None
// RETURN: void
// LOGIC:
// 1. Display admin menu
// 2. Accept choice
// 3. Call appropriate function
// 4. Repeat until logout
// CONCEPTS USED:
// - Do-while loop
// - Switch statement
// - Function calls
// - Menu-driven programming
// WHY NEEDED: Central control for admin operations
// INTERACTION: Calls all admin functions
// ============================================================
void adminPanel() {
    int choice;
    
    do {
        displayAdminMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        if (!validateChoice(choice, 1, 15)) {
            cout << "Invalid choice! Please try again." << endl;
            pauseSystem();
            continue;
        }
        
        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
                
            case 2:
                displayStudents(students, studentCount);
                break;
                
            case 3: {
                clearScreen();
                displayHeader("SEARCH STUDENT");
                int studentId;
                cout << "Enter Student ID: ";
                cin >> studentId;
                cin.ignore();
                int index = searchStudent(students, studentCount, studentId);
                if (index != -1) {
                    cout << "\nStudent Found!" << endl;
                    displayLine();
                    displayStudentInfo(students[index]);
                } else {
                    cout << "\nStudent not found!" << endl;
                }
                pauseSystem();
                break;
            }
            
            case 4:
                updateStudent(students, studentCount);
                break;
                
            case 5:
                deleteStudent(students, studentCount);
                break;
                
            case 6:
                createExam(exams, examCount);
                break;
                
            case 7:
                addQuestion(exams, examCount);
                break;
                
            case 8:
                editQuestion(exams, examCount);
                break;
                
            case 9:
                deleteQuestion(exams, examCount);
                break;
                
            case 10:
                updateExam(exams, examCount);
                break;
                
            case 11:
                deleteExam(exams, examCount);
                break;
                
            case 12:
                displayExams(exams, examCount);
                break;
                
            case 13:
                displayAllResults(results, resultCount);
                break;
                
            case 14:
                clearScreen();
                displayHeader("SAVE DATA");
                saveStudentsToFile(students, studentCount);
                saveExamsToFile(exams, examCount);
                saveResultsToFile(results, resultCount);
                cout << "\nAll data saved successfully!" << endl;
                pauseSystem();
                break;
                
            case 15:
                cout << "\nLogging out..." << endl;
                pauseSystem();
                break;
        }
        
    } while (choice != 15);
}

// ============================================================
// FUNCTION: displayStudentMenu
// ============================================================
// PURPOSE: Display student menu options
// PARAMETERS: None
// RETURN: void
// LOGIC: Display student functionalities
// CONCEPTS USED:
// - Output formatting
// - Menu design
// WHY NEEDED: Student interface for exam operations
// INTERACTION: Called by studentPanel
// ============================================================
void displayStudentMenu() {
    clearScreen();
    displayHeader("STUDENT PANEL");
    cout << "\n1. View Available Exams" << endl;
    cout << "2. Take Exam" << endl;
    cout << "3. View My Results" << endl;
    cout << "4. Logout" << endl;
    displayLine();
}

// ============================================================
// FUNCTION: studentPanel
// ============================================================
// PURPOSE: Handle student operations
// PARAMETERS:
// - studentId: ID of logged-in student
// RETURN: void
// LOGIC:
// 1. Display student menu
// 2. Accept choice
// 3. Call appropriate function
// 4. Repeat until logout
// CONCEPTS USED:
// - Do-while loop
// - Switch statement
// - Function calls
// - Menu-driven programming
// WHY NEEDED: Central control for student operations
// INTERACTION: Calls exam and result functions
// ============================================================
void studentPanel(int studentId) {
    int choice;
    
    do {
        displayStudentMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        if (!validateChoice(choice, 1, 4)) {
            cout << "Invalid choice! Please try again." << endl;
            pauseSystem();
            continue;
        }
        
        switch (choice) {
            case 1:
                displayExams(exams, examCount);
                break;
                
            case 2:
                takeExam(exams, examCount, studentId, results, resultCount);
                break;
                
            case 3:
                displayStudentResults(results, resultCount, studentId);
                break;
                
            case 4:
                cout << "\nLogging out..." << endl;
                pauseSystem();
                break;
        }
        
    } while (choice != 4);
}
