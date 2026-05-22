#include <iostream>
#include <vector>
#include "student.h"
#include "exam.h"
#include "result.h"
#include "filemanager.h"
#include "utility.h"

using namespace std;

enum UserRole {
    ADMIN = 1,
    STUDENT = 2
};

vector<StudentType> students;
vector<ExamType> exams;
vector<ResultType> results;

void displayMainMenu();
bool adminLogin();
bool studentLogin(string &studentId);
void handleMenuChoice(int choice, bool &isAdminLoggedIn, bool &isStudentLoggedIn, string &loggedInStudentId);

int main() {
    loadStudentsFromFile(students);
    loadExamsFromFile(exams);
    loadResultsFromFile(results);
    
    bool isAdminLoggedIn = false;
    bool isStudentLoggedIn = false;
    string loggedInStudentId = "";
    int choice;
    
    do {
        displayMainMenu();
        
        if (isAdminLoggedIn) {
            cout << "\n[ADMIN LOGGED IN]" << endl;
        } else if (isStudentLoggedIn) {
            cout << "\n[STUDENT LOGGED IN - ID: " << loggedInStudentId << "]" << endl;
        } else {
            cout << "\n[NOT LOGGED IN]" << endl;
        }
        
        cout << "\nEnter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            pauseSystem();
            continue;
        }
        cin.ignore();
        
        if (!validateChoice(choice, 1, 22)) {
            cout << "Invalid choice! Please enter a number between 1 and 22." << endl;
            pauseSystem();
            continue;
        }
        
        handleMenuChoice(choice, isAdminLoggedIn, isStudentLoggedIn, loggedInStudentId);
        
    } while (choice != 22);
    
    return 0;
}

void displayMainMenu() {
    clearScreen();
    displayHeader("ONLINE EXAM MANAGEMENT SYSTEM");
    
    cout << "\n=== ADMIN PANEL ===" << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. Add Student" << endl;
    cout << "3. Display All Students" << endl;
    cout << "4. Search Student" << endl;
    cout << "5. Update Student" << endl;
    cout << "6. Delete Student" << endl;
    cout << "7. Create Exam" << endl;
    cout << "8. Add Question to Exam" << endl;
    cout << "9. Edit Question" << endl;
    cout << "10. Delete Question" << endl;
    cout << "11. Update Exam" << endl;
    cout << "12. Delete Exam" << endl;
    cout << "13. Display All Exams" << endl;
    cout << "14. View All Results" << endl;
    cout << "15. Save Data" << endl;
    cout << "16. Admin Logout" << endl;
    
    cout << "\n=== STUDENT PANEL ===" << endl;
    cout << "17. Student Login" << endl;
    cout << "18. View Available Exams" << endl;
    cout << "19. Take Exam" << endl;
    cout << "20. View My Results" << endl;
    cout << "21. Student Logout" << endl;
    
    cout << "\n=== SYSTEM ===" << endl;
    cout << "22. Exit" << endl;
    displayLine();
}

bool adminLogin() {
    clearScreen();
    displayHeader("ADMIN LOGIN");
    
    string username, password;
    
    cout << "Enter Username: ";
    getline(cin, username);
    
    cout << "Enter Password: ";
    getline(cin, password);
    
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

bool studentLogin(string &studentId) {
    clearScreen();
    displayHeader("STUDENT LOGIN");
    
    string id;
    string password;
    
    cout << "Enter Student ID: ";
    getline(cin, id);
    
    cout << "Enter Password: ";
    getline(cin, password);
    
    int index = searchStudent(students, id);
    
    if (index != -1 && students[index].verifyPassword(password)) {
        studentId = id;
        cout << "\nLogin successful!" << endl;
        cout << "Welcome, " << students[index].getFullName() << "!" << endl;
        pauseSystem();
        return true;
    }
    
    cout << "\nInvalid credentials!" << endl;
    pauseSystem();
    return false;
}

void handleMenuChoice(int choice, bool &isAdminLoggedIn, bool &isStudentLoggedIn, string &loggedInStudentId) {
    if (choice == 1) {
        if (isAdminLoggedIn) {
            cout << "\nAlready logged in as Admin!" << endl;
            pauseSystem();
        } else {
            isAdminLoggedIn = adminLogin();
            if (isAdminLoggedIn) {
                isStudentLoggedIn = false;
                loggedInStudentId = "";
            }
        }
        return;
    }
    
    if (choice == 16) {
        if (!isAdminLoggedIn) {
            cout << "\nYou are not logged in as Admin!" << endl;
            pauseSystem();
        } else {
            clearScreen();
            displayHeader("ADMIN LOGOUT");
            cout << "\nLogging out..." << endl;
            isAdminLoggedIn = false;
            cout << "Admin logged out successfully!" << endl;
            pauseSystem();
        }
        return;
    }
    
    if (choice == 17) {
        if (isStudentLoggedIn) {
            cout << "\nAlready logged in as Student!" << endl;
            pauseSystem();
        } else {
            isStudentLoggedIn = studentLogin(loggedInStudentId);
            if (isStudentLoggedIn) {
                isAdminLoggedIn = false;
            }
        }
        return;
    }
    
    if (choice == 21) {
        if (!isStudentLoggedIn) {
            cout << "\nYou are not logged in as Student!" << endl;
            pauseSystem();
        } else {
            clearScreen();
            displayHeader("STUDENT LOGOUT");
            cout << "\nLogging out..." << endl;
            cout << "Goodbye, " << loggedInStudentId << "!" << endl;
            isStudentLoggedIn = false;
            loggedInStudentId = "";
            cout << "Student logged out successfully!" << endl;
            pauseSystem();
        }
        return;
    }
    
    if (choice >= 2 && choice <= 15) {
        if (!isAdminLoggedIn) {
            cout << "\nAccess Denied! Please login as Admin first." << endl;
            pauseSystem();
            return;
        }
        
        switch (choice) {
            case 2:
                addStudent(students);
                break;
            case 3:
                displayStudents(students);
                break;
            case 4: {
                clearScreen();
                displayHeader("SEARCH STUDENT");
                string studentId;
                cout << "Enter Student ID: ";
                getline(cin, studentId);
                int index = searchStudent(students, studentId);
                if (index != -1) {
                    cout << "\nStudent Found!" << endl;
                    displayLine();
                    students[index].displayStudentInfo();
                } else {
                    cout << "\nStudent not found!" << endl;
                }
                pauseSystem();
                break;
            }
            case 5:
                updateStudent(students);
                break;
            case 6:
                deleteStudent(students, results);
                break;
            case 7:
                createExam(exams);
                break;
            case 8:
                addQuestion(exams);
                break;
            case 9:
                editQuestion(exams);
                break;
            case 10:
                deleteQuestion(exams);
                break;
            case 11:
                updateExam(exams);
                break;
            case 12:
                deleteExam(exams, results);
                break;
            case 13:
                displayExams(exams);
                break;
            case 14:
                displayAllResults(results);
                break;
            case 15:
                clearScreen();
                displayHeader("SAVE DATA");
                saveStudentsToFile(students);
                saveExamsToFile(exams);
                saveResultsToFile(results);
                cout << "\nAll data saved successfully!" << endl;
                cout << "Students: " << students.size() << " | Exams: " << exams.size() << " | Results: " << results.size() << endl;
                pauseSystem();
                break;
        }
    }
    
    if (choice >= 18 && choice <= 20) {
        if (!isStudentLoggedIn) {
            cout << "\nAccess Denied! Please login as Student first." << endl;
            pauseSystem();
            return;
        }
        
        switch (choice) {
            case 18:
                displayExams(exams);
                break;
            case 19:
                takeExam(exams, loggedInStudentId, results);
                break;
            case 20:
                displayStudentResults(results, loggedInStudentId);
                break;
        }
    }
    
    if (choice == 22) {
        cout << "\nSaving data..." << endl;
        saveStudentsToFile(students);
        saveExamsToFile(exams);
        saveResultsToFile(results);
        cout << "Data saved successfully!" << endl;
        cout << "\nThank you for using Online Exam Management System!" << endl;
        
        if (isAdminLoggedIn) {
            isAdminLoggedIn = false;
        }
        if (isStudentLoggedIn) {
            isStudentLoggedIn = false;
            loggedInStudentId = "";
        }
    }
}
