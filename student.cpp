#include "student.h"
#include "result.h"
#include "utility.h"
#include "filemanager.h"
#include <iostream>
using namespace std;

// Date class implementation
Date::Date() {
    day = 1;
    month = 1;
    year = 2026;
}

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }

void Date::inputDate() {
    while (true) {
        cout << "Enter Day (1-30): ";
        if (!(cin >> day)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        cout << "Enter Month (1-12): ";
        if (!(cin >> month)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        cout << "Enter Year: ";
        if (!(cin >> year)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        if (isValid()) {
            break;
        } else {
            cout << "Error: Invalid date! Please try again." << endl;
        }
    }
}

void Date::displayDate() const {
    cout << day << "/" << month << "/" << year;
}

bool Date::isValid() const {
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 30) return false;
    
    return true;
}

// Student class implementation
Student::Student() {
    studentId = "";
    fullName = "";
    department = "";
    password = "";
    registrationDate = DateType();
}

Student::Student(string id, string name, string dept, string pass, DateType date) {
    studentId = id;
    fullName = name;
    department = dept;
    password = pass;
    registrationDate = date;
}

string Student::getStudentId() const { return studentId; }
string Student::getFullName() const { return fullName; }
string Student::getDepartment() const { return department; }
string Student::getPassword() const { return password; }
DateType Student::getRegistrationDate() const { return registrationDate; }

void Student::setStudentId(string id) { studentId = id; }
void Student::setFullName(string name) { fullName = name; }
void Student::setDepartment(string dept) { department = dept; }
void Student::setPassword(string pass) { password = pass; }
void Student::setRegistrationDate(DateType date) { registrationDate = date; }

void Student::inputStudentData() {
    cout << "Enter Student ID: ";
    getline(cin, studentId);
    
    cout << "Enter Full Name: ";
    getline(cin, fullName);
    
    cout << "Enter Department: ";
    getline(cin, department);
    
    cout << "Enter Password: ";
    getline(cin, password);
    
    cout << "\n--- Registration Date ---" << endl;
    registrationDate.inputDate();
}

void Student::displayStudentInfo() const {
    cout << "Student ID: " << studentId << endl;
    cout << "Name: " << fullName << endl;
    cout << "Department: " << department << endl;
    cout << "Registration Date: ";
    registrationDate.displayDate();
    cout << endl;
}

bool Student::verifyPassword(string pass) const {
    return password == pass;
}

// Module-level functions using vector
void addStudent(vector<StudentType> &students) {
    clearScreen();
    displayHeader("ADD NEW STUDENTS");
    
    int numStudents;
    while (true) {
        cout << "How many students do you want to add? ";
        if (!(cin >> numStudents)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        cin.ignore();
        
        if (numStudents <= 0) {
            cout << "Error: Number must be positive!" << endl;
            continue;
        }
        
        break;
    }
    
    int addedCount = 0;
    
    for (int i = 0; i < numStudents; i++) {
        clearScreen();
        displayHeader("ADD STUDENT");
        cout << "Adding student " << (i + 1) << " of " << numStudents << endl;
        displayLine();
        
        StudentType newStudent;
        string tempId;
        
        while (true) {
            cout << "\nEnter Student ID (or type 'exit' to stop): ";
            getline(cin, tempId);
            
            if (tempId == "exit" || tempId == "EXIT") {
                cout << "\nStopping student addition..." << endl;
                goto save_and_exit;
            }
            
            if (tempId.empty()) {
                cout << "Error: Student ID cannot be empty!" << endl;
                continue;
            }
            
            if (searchStudent(students, tempId) != -1) {
                cout << "Error: Student ID already exists! Try another ID." << endl;
                continue;
            }
            
            break;
        }
        newStudent.setStudentId(tempId);
        
        string tempName;
        while (true) {
            cout << "Enter Full Name: ";
            getline(cin, tempName);
            
            if (tempName.empty()) {
                cout << "Error: Name cannot be empty!" << endl;
                continue;
            }
            break;
        }
        newStudent.setFullName(tempName);
        
        string tempDept;
        while (true) {
            cout << "Enter Department: ";
            getline(cin, tempDept);
            
            if (tempDept.empty()) {
                cout << "Error: Department cannot be empty!" << endl;
                continue;
            }
            break;
        }
        newStudent.setDepartment(tempDept);
        
        string tempPass;
        while (true) {
            cout << "Enter Password: ";
            getline(cin, tempPass);
            
            if (tempPass.empty()) {
                cout << "Error: Password cannot be empty!" << endl;
                continue;
            }
            break;
        }
        newStudent.setPassword(tempPass);
        
        cout << "\n--- Registration Date ---" << endl;
        DateType tempDate;
        while (true) {
            tempDate.inputDate();
            
            if (!tempDate.isValid()) {
                cout << "Error: Invalid date! Please enter again." << endl;
                continue;
            }
            break;
        }
        newStudent.setRegistrationDate(tempDate);
        
        students.push_back(newStudent);
        addedCount++;
        
        cout << "\nStudent " << (i + 1) << " added successfully!" << endl;
        
        if (i < numStudents - 1) {
            cout << "\nPress Enter to add next student...";
            cin.get();
        }
    }
    
save_and_exit:
    if (addedCount > 0) {
        saveStudentsToFile(students);
        cout << "\n" << addedCount << " student(s) added successfully!" << endl;
        cout << "Data saved to file automatically." << endl;
        cout << "Total students: " << students.size() << endl;
    } else {
        cout << "\nNo students were added." << endl;
    }
    
    pauseSystem();
}

void displayStudents(const vector<StudentType> &students) {
    clearScreen();
    displayHeader("ALL STUDENTS");
    
    if (students.empty()) {
        cout << "No students registered yet." << endl;
        pauseSystem();
        return;
    }
    
    for (size_t i = 0; i < students.size(); i++) {
        cout << "\n--- Student " << (i + 1) << " ---" << endl;
        students[i].displayStudentInfo();
        displayLine();
    }
    
    cout << "\nTotal Students: " << students.size() << endl;
    pauseSystem();
}

int searchStudent(const vector<StudentType> &students, string studentId) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].getStudentId() == studentId) {
            return i;
        }
    }
    return -1;
}

void updateStudent(vector<StudentType> &students) {
    clearScreen();
    displayHeader("UPDATE STUDENT");
    
    if (students.empty()) {
        cout << "No students to update." << endl;
        pauseSystem();
        return;
    }
    
    string studentId;
    cout << "Enter Student ID to update: ";
    getline(cin, studentId);
    
    int index = searchStudent(students, studentId);
    
    if (index == -1) {
        cout << "Student not found!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\n--- Current Information ---" << endl;
    students[index].displayStudentInfo();
    
    cout << "\n--- Enter New Information ---" << endl;
    
    string newName;
    while (true) {
        cout << "Enter Full Name: ";
        getline(cin, newName);
        if (!newName.empty()) break;
        cout << "Error: Name cannot be empty!" << endl;
    }
    students[index].setFullName(newName);
    
    string newDept;
    while (true) {
        cout << "Enter Department: ";
        getline(cin, newDept);
        if (!newDept.empty()) break;
        cout << "Error: Department cannot be empty!" << endl;
    }
    students[index].setDepartment(newDept);
    
    string newPass;
    while (true) {
        cout << "Enter Password: ";
        getline(cin, newPass);
        if (!newPass.empty()) break;
        cout << "Error: Password cannot be empty!" << endl;
    }
    students[index].setPassword(newPass);
    
    saveStudentsToFile(students);
    
    cout << "\nStudent updated successfully!" << endl;
    cout << "Data saved to file automatically." << endl;
    pauseSystem();
}

void deleteStudent(vector<StudentType> &students, vector<Result> &results) {
    clearScreen();
    displayHeader("DELETE STUDENT");
    
    if (students.empty()) {
        cout << "No students to delete." << endl;
        pauseSystem();
        return;
    }
    
    string studentId;
    cout << "Enter Student ID to delete: ";
    getline(cin, studentId);
    
    int index = searchStudent(students, studentId);
    
    if (index == -1) {
        cout << "Student not found!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\n--- Student to Delete ---" << endl;
    students[index].displayStudentInfo();
    
    int resultCount = 0;
    for (size_t i = 0; i < results.size(); i++) {
        if (results[i].getStudentId() == studentId) {
            resultCount++;
        }
    }
    
    if (resultCount > 0) {
        cout << "\nWARNING: This student has " << resultCount << " exam result(s)." << endl;
        cout << "Deleting the student will also delete all their results!" << endl;
    }
    
    char confirm;
    cout << "\nAre you sure you want to delete? (y/n): ";
    cin >> confirm;
    cin.ignore();
    
    if (confirm == 'y' || confirm == 'Y') {
        students.erase(students.begin() + index);
        
        for (size_t i = 0; i < results.size(); ) {
            if (results[i].getStudentId() == studentId) {
                results.erase(results.begin() + i);
            } else {
                i++;
            }
        }
        
        saveStudentsToFile(students);
        saveResultsToFile(results);
        
        cout << "\nStudent deleted successfully!" << endl;
        if (resultCount > 0) {
            cout << resultCount << " result(s) also deleted." << endl;
        }
        cout << "Data saved to file automatically." << endl;
        cout << "Total students: " << students.size() << endl;
    } else {
        cout << "Deletion cancelled." << endl;
    }
    
    pauseSystem();
}

bool studentLogin(const vector<StudentType> &students, string &loggedInStudentId) {
    clearScreen();
    displayHeader("STUDENT LOGIN");
    
    string studentId;
    string password;
    
    cout << "Enter Student ID: ";
    getline(cin, studentId);
    
    cout << "Enter Password: ";
    getline(cin, password);
    
    int index = searchStudent(students, studentId);
    
    if (index != -1 && students[index].verifyPassword(password)) {
        loggedInStudentId = studentId;
        cout << "\nLogin successful!" << endl;
        cout << "Welcome, " << students[index].getFullName() << "!" << endl;
        pauseSystem();
        return true;
    }
    
    cout << "\nInvalid credentials!" << endl;
    pauseSystem();
    return false;
}
