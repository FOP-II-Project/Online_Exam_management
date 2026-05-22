#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

// Date class
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    
    void inputDate();
    void displayDate() const;
    bool isValid() const;
};

typedef Date DateType;

// Student class
class Student {
private:
    string studentId;
    string fullName;
    string department;
    string password;
    DateType registrationDate;

public:
    Student();
    Student(string id, string name, string dept, string pass, DateType date);
    
    string getStudentId() const;
    string getFullName() const;
    string getDepartment() const;
    string getPassword() const;
    DateType getRegistrationDate() const;
    
    void setStudentId(string id);
    void setFullName(string name);
    void setDepartment(string dept);
    void setPassword(string pass);
    void setRegistrationDate(DateType date);
    
    void inputStudentData();
    void displayStudentInfo() const;
    bool verifyPassword(string pass) const;
};

typedef Student StudentType;

// Functions using vector (STL)
void addStudent(vector<StudentType> &students);
void displayStudents(const vector<StudentType> &students);
int searchStudent(const vector<StudentType> &students, string studentId);
void updateStudent(vector<StudentType> &students);
void deleteStudent(vector<StudentType> &students);
bool studentLogin(const vector<StudentType> &students, string &loggedInStudentId);

#endif
