# Online Exam Management System

<div align="center">

![AASTU Logo](https://colab.ws/storage/images/resized/5BW4arMB4UuTuBZJkpu6pq727oxlLzOA9qPpQl4d_medium.webp)

**Addis Ababa Science and Technology University**

[![C++](https://img.shields.io/badge/C++-11-blue.svg)](https://isocpp.org/)
[![STL](https://img.shields.io/badge/STL-Vector-green.svg)](https://en.cppreference.com/w/cpp/container/vector)
[![Platform](https://img.shields.io/badge/Platform-Cross--Platform-green.svg)](https://github.com/)

</div>

---

## 📋 Project Information

**University:** Addis Ababa Science and Technology University  
**College:** College of Engineering  
**Department:** Department of Software Engineering  
**Course:** Fundamentals of Programming  
**Section:** D  
**Group:** 5

### 👥 Group Members

| No. | Name | ID Number |
|-----|------|-----------|
| 1 | Abraham Amogne | ETS1848/17 |
| 2 | Saron Anbesaw | ETS1309/17 |
| 3 | Seble Sisay | ETS1314/17 |
| 4 | Senet Anbesaw | ETS1332/17 |
| 5 | Shanble Dires | ETS1336/17 |
| 6 | Zeynu Aman | ETS1622/17 |

---

## 📑 Table of Contents

- [Project Overview](#-project-overview)
- [System Architecture](#-system-architecture)
- [Key Features](#-key-features)
- [Programming Concepts](#-programming-concepts-demonstrated)
- [How It Works](#-how-the-system-works)
- [Installation & Setup](#-installation--setup)
- [Usage Guide](#-usage-guide)
- [File Structure](#-file-structure)
- [Data Management](#-data-management)
- [Technical Specifications](#-technical-specifications)

---

## 🎯 Project Overview

### Purpose

The **Online Exam Management System** is a comprehensive console-based application designed to automate and streamline the complete examination lifecycle in educational institutions. This system demonstrates practical implementation of **Object-Oriented Programming (OOP)**, **STL containers**, and **modern C++ concepts** while solving real-world problems in academic administration.

### Problem Statement

Traditional paper-based examination systems face numerous challenges:
- Manual student registration and record management
- Time-consuming exam creation and question bank management
- Delayed result processing and grade calculation
- Difficulty in maintaining historical records
- Lack of instant feedback for students
- Inefficient data storage and retrieval
- Fixed capacity limitations

### Solution

This system provides a digital solution that:
- Automates student registration and authentication
- Enables rapid exam creation with dynamic question banks
- Provides instant result calculation and grade assignment
- Maintains persistent data storage with professional formatting
- Offers role-based access (Admin and Student)
- Generates comprehensive reports for analysis
- **Uses STL vectors for dynamic, unlimited storage**
- **Implements OOP principles with classes and encapsulation**

---

## 🏗️ System Architecture

### Modular Design with OOP

The system follows a **modular architecture** with **class-based design** and clear separation of concerns:

```
┌─────────────────────────────────────────────────────────┐
│                      MAIN PROGRAM                        │
│         (Menu Coordination & Flow Control)               │
└────────────┬────────────────────────────────────────────┘
             │
    ┌────────┴────────┬──────────┬──────────┬──────────┐
    │                 │          │          │          │
┌───▼────┐    ┌──────▼─────┐ ┌──▼─────┐ ┌──▼──────┐ ┌▼────────┐
│STUDENT │    │    EXAM    │ │ RESULT │ │  FILE   │ │ UTILITY │
│ CLASS  │    │   CLASS    │ │ CLASS  │ │ MANAGER │ │ MODULE  │
└────────┘    └────────────┘ └────────┘ └─────────┘ └─────────┘
```

### Class Architecture

**Core Classes:**
- **Date Class** - Encapsulates date information with validation
- **Student Class** - Manages student data with private members and public methods
- **Question Class** - Represents individual exam questions
- **Exam Class** - Contains vector of questions, manages exam lifecycle
- **Result Class** - Handles grade calculation and result display

### Module Responsibilities

| Module | Responsibility | Key Components |
|--------|---------------|----------------|
| **Student** | User management and authentication | Student class, Date class, CRUD operations |
| **Exam** | Exam and question management | Exam class, Question class, vector operations |
| **Result** | Grade calculation and reporting | Result class, percentage calculation |
| **FileManager** | Data persistence | Save/Load with vector support |
| **Utility** | Helper functions and templates | Template functions, validation |
| **Main** | Program coordination | Menu handling, Flow control |

---

## ✨ Key Features

### 1. Student Management System

**Description:** Complete lifecycle management of student records with OOP design.

**Capabilities:**
- **Registration:** Admin registers students with unique IDs
- **Authentication:** Secure login with ID and password verification
- **Profile Management:** Update student information
- **Search Functionality:** Quick lookup by student ID
- **Record Deletion:** Remove students with confirmation
- **Data Validation:** Ensures data integrity (no duplicates, valid dates 1-30 for all months)
- **Dynamic Storage:** Uses `vector<Student>` for unlimited capacity

**Technical Implementation:**
- `Student` class with private data members
- Public accessor methods (getters/setters)
- Encapsulation of student data
- Vector-based storage with `push_back()`, `erase()`
- No fixed size limits

### 2. Exam Creation & Management

**Description:** Comprehensive exam lifecycle management with dynamic question banks.

**Capabilities:**
- **Exam Creation:** Define exams with course name, duration, unique ID
- **Dynamic Question Bank:** Add unlimited questions using vectors
- **Question Editing:** Modify existing questions
- **Question Deletion:** Remove questions with automatic re-indexing
- **Exam Updates:** Modify exam details
- **Exam Deletion:** Remove entire exams
- **Status Management:** Control exam availability (Active/Inactive/Completed)

**Technical Implementation:**
- `Exam` class with `vector<Question>` for questions
- `Question` class with encapsulated data
- Enum-based status control
- Vector operations: `push_back()`, `erase()`, `size()`
- No question count limits

### 3. Interactive Exam Taking

**Description:** Real-time exam interface with instant scoring and feedback.

**Student Experience:**
```
Login → View Exams → Select Exam → Answer Questions → See Results Immediately
```

**Scoring System:**
- Automatic score calculation
- Percentage computation
- Grade assignment (A, B, C, D, F)
- Pass/Fail determination (50% threshold)

### 4. Result Management & Reporting

**Description:** Comprehensive result tracking with instant feedback.

**Result Display Format:**
```
Student ID   : 1001
Exam ID      : 101
Score        : 30 / 30
Percentage   : 100.00%
Grade        : A
Status       : PASSED
```

**Grading Scale:**
| Percentage | Grade | Status |
|------------|-------|--------|
| 90-100%    | A     | Pass   |
| 80-89%     | B     | Pass   |
| 70-79%     | C     | Pass   |
| 60-69%     | D     | Pass   |
| Below 60%  | F     | Fail   |

**Features:**
- Students see results immediately after exam completion
- Personal dashboard shows all exam results
- Admin can view all results
- Results stored in `vector<Result>` for unlimited capacity

### 5. Professional File Handling

**Description:** Robust data persistence with human-readable formats.

**File Format Example (students.txt):**
```
STUDENT RECORDS DATABASE
Total Students: 3
========================================

----------------------------------------
Student ID   : 1001
Name         : John Doe
Department   : Computer Science
Password     : john123
Reg. Date    : 15/05/2026
----------------------------------------
```

**Capabilities:**
- Automatic saving on program exit
- Manual save option for admin
- Silent background loading on startup
- Professional labeled format
- Vector-based save/load operations

### 6. Role-Based Access Control

**Main Menu (Shows Features Upfront):**
```
ONLINE EXAM MANAGEMENT SYSTEM
============================================================

=== ADMIN PANEL FEATURES ===
• Student Management (Add, Update, Delete, Search)
• Exam Management (Create, Update, Delete)
• Question Bank Management
• View All Results & Reports

=== STUDENT PANEL FEATURES ===
• View Available Exams
• Take Exams Interactively
• View Personal Results

============================================================

1. Admin Login
2. Student Login
3. Exit
```

**Admin Panel (After Login):**
```
ADMIN PANEL
========================================

--- Student Management ---
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student

--- Exam Management ---
6. Create Exam
7. Add Question to Exam
8. Edit Question
9. Delete Question
10. Update Exam
11. Delete Exam
12. Display All Exams

--- Result Management ---
13. View All Results

--- System ---
14. Save Data
15. Logout
```

**Student Panel:**
```
STUDENT PANEL
========================================

1. View Available Exams
2. Take Exam
3. View My Results
4. Logout
```

---

## 💻 Programming Concepts Demonstrated

### 1. Object-Oriented Programming (OOP) with Classes

**Classes Implemented:**

The project uses **classes** for data organization with encapsulation:

```cpp
// Date class with private members
class Date {
private:
    int day, month, year;
public:
    Date();  // Default constructor
    Date(int d, int m, int y);  // Parameterized constructor
    
    // Getters and Setters
    int getDay() const;
    void setDay(int d);
    
    // Methods
    void inputDate();
    void displayDate() const;
    bool isValid() const;
};
```

```cpp
// Student class
class Student {
private:
    int studentId;
    string fullName;
    string department;
    string password;
    DateType registrationDate;
public:
    Student();
    Student(int id, string name, string dept, string pass, DateType date);
    
    // Getters and Setters
    int getStudentId() const;
    void setStudentId(int id);
    
    // Methods
    void inputStudentData();
    void displayStudentInfo() const;
    bool verifyPassword(string pass) const;
};

// Exam class with vector of questions
class Exam {
private:
    int examId;
    string courseName;
    int durationMinutes;
    vector<QuestionType> questions;  // Dynamic storage
    ExamStatusType status;
public:
    Exam();
    Exam(int id, string course, int duration);
    
    // Methods
    void addQuestion(QuestionType q);
    bool editQuestion(int questionNum);
    bool deleteQuestion(int questionNum);
    int getTotalQuestions() const { return questions.size(); }
};
```

**OOP Principles Applied:**
- **Encapsulation:** Private data members, public methods
- **Constructors:** Default and parameterized constructors
- **Accessor Methods:** Getters and setters for controlled access
- **Data Hiding:** Internal implementation hidden from users
- **Const Correctness:** Const methods for read-only operations

**Note:** In C++, `class` and `struct` are nearly identical - the only difference is default access (private for class, public for struct). This project uses `class` with explicit `private:` and `public:` sections to demonstrate encapsulation principles clearly.

### 2. STL Containers (Vector)

**Implementation:**

```cpp
// Global vectors for dynamic storage
vector<StudentType> students;  // No size limit
vector<ExamType> exams;        // No size limit
vector<ResultType> results;    // No size limit

// Adding elements
students.push_back(newStudent);

// Getting size
cout << "Total students: " << students.size() << endl;

// Accessing elements
for (size_t i = 0; i < students.size(); i++) {
    students[i].displayStudentInfo();
}

// Deleting elements
students.erase(students.begin() + index);

// Checking if empty
if (students.empty()) {
    cout << "No students registered" << endl;
}
```

**Benefits of Vector:**
- Dynamic size (grows automatically)
- No fixed capacity limits
- Memory managed automatically
- Standard library support
- Easy iteration

**Before (Arrays) vs After (Vectors):**

| Arrays | Vectors |
|--------|---------|
| `StudentType students[100];` | `vector<StudentType> students;` |
| `int studentCount = 0;` | No count variable needed |
| `students[count++] = newStudent;` | `students.push_back(newStudent);` |
| Manual capacity checking | Grows automatically |

### 3. Enumerations

```cpp
// Exam status enumeration
enum ExamStatus {
    ACTIVE,      // 0
    INACTIVE,    // 1
    COMPLETED    // 2
};

// Usage
ExamType exam;
exam.setStatus(ACTIVE);

if (exam.getStatus() == ACTIVE) {
    cout << "Exam is available" << endl;
}
```

### 4. Typedef

```cpp
// Type aliases for cleaner code
typedef Date DateType;
typedef Student StudentType;
typedef Question QuestionType;
typedef Exam ExamType;
typedef Result ResultType;

// Usage
vector<StudentType> students;  // Instead of vector<Student>
```

### 5. Template Functions

```cpp
// Generic swap function
template <typename T>
void swapData(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Works with any type
int x = 5, y = 10;
swapData(x, y);  // Swaps integers

string a = "Hello", b = "World";
swapData(a, b);  // Swaps strings
```

### 6. File Handling with Vectors

```cpp
// Save vector to file
void saveStudentsToFile(const vector<StudentType> &students) {
    ofstream outFile("students.txt");
    outFile << "Total Students: " << students.size() << endl;
    
    for (size_t i = 0; i < students.size(); i++) {
        outFile << "Student ID: " << students[i].getStudentId() << endl;
    }
    outFile.close();
}

// Load vector from file
void loadStudentsFromFile(vector<StudentType> &students) {
    ifstream inFile("students.txt");
    students.clear();  // Clear existing data
    // Read and parse data
    students.push_back(tempStudent);  // Add to vector
    inFile.close();
}
```

### 7. Modular Programming

**File Structure:**
- `student.h / student.cpp` - Student and Date classes
- `exam.h / exam.cpp` - Exam and Question classes
- `result.h / result.cpp` - Result class
- `filemanager.h / .cpp` - File I/O operations
- `utility.h / utility.cpp` - Helper functions
- `main.cpp` - Program entry point

**Benefits:**
- Easy to maintain and debug
- Reusable components
- Clear responsibility boundaries
- Team collaboration friendly

### 8. Class vs Struct in C++

**Understanding the Difference:**

In C++, `class` and `struct` are nearly identical. The **only difference** is:
- **class:** Members are `private` by default
- **struct:** Members are `public` by default

**This Project Uses Classes:**
```cpp
class Student {
private:    // Explicit private section
    int studentId;
    string fullName;
public:     // Explicit public section
    Student();
    int getStudentId() const;
};
```

**Could Also Use Struct:**
```cpp
struct Student {
    // Would need explicit private: section
private:
    int studentId;
    string fullName;
public:
    Student();
    int getStudentId() const;
};
```

**Why Classes Are Used Here:**
- Demonstrates encapsulation explicitly
- Common convention for OOP
- Clear separation of interface (public) and implementation (private)
- Better for academic learning of OOP principles

---

## 🔄 How the System Works

### System Workflow

```
┌─────────────────────────────────────────────────────────────┐
│                    PROGRAM STARTUP                           │
│  • Load students.txt → vector<Student>                       │
│  • Load exams.txt → vector<Exam>                            │
│  • Load results.txt → vector<Result>                        │
│  • Silent background loading (no console output)             │
└────────────────────────┬────────────────────────────────────┘
                         │
                         ▼
┌─────────────────────────────────────────────────────────────┐
│                    MAIN MENU                                 │
│  ┌─────────────┐  ┌─────────────┐  ┌─────────────┐        │
│  │   Admin     │  │   Student   │  │    Exit     │        │
│  │   Login     │  │   Login     │  │  (Save All) │        │
│  └──────┬──────┘  └──────┬──────┘  └─────────────┘        │
└─────────┼─────────────────┼────────────────────────────────┘
          │                 │
          ▼                 ▼
┌──────────────────┐  ┌──────────────────┐
│   ADMIN PANEL    │  │  STUDENT PANEL   │
│  (15 options)    │  │  (4 options)     │
└──────────────────┘  └──────────────────┘
```

### Student Workflow

```
┌─────────────────────────────────────────────────────────────┐
│  1. LOGIN                                                    │
│     Enter ID → Enter Password → Verify → Grant Access       │
├─────────────────────────────────────────────────────────────┤
│  2. VIEW AVAILABLE EXAMS                                     │
│     Display all ACTIVE exams from vector                     │
├─────────────────────────────────────────────────────────────┤
│  3. TAKE EXAM                                                │
│     Select Exam → Check if already taken                     │
│     For each question in exam.questions vector:              │
│       Display question                                       │
│       Accept answer                                          │
│       Calculate score                                        │
│     Calculate percentage & grade                             │
│     Create Result object                                     │
│     results.push_back(newResult)                            │
│     Display results IMMEDIATELY                              │
├─────────────────────────────────────────────────────────────┤
│  4. VIEW MY RESULTS                                          │
│     Filter results vector by studentId                       │
│     Display all personal results                             │
└─────────────────────────────────────────────────────────────┘
```

---

## 🚀 Installation & Setup

### Prerequisites

- **C++ Compiler:** g++ (MinGW), MSVC, or Clang
- **C++ Standard:** C++11 or higher (for vector support)
- **Operating System:** Windows, Linux, or macOS

### Compilation

**Command Line:**
```bash
g++ -std=c++11 -Wall -Wextra main.cpp student.cpp exam.cpp result.cpp filemanager.cpp utility.cpp -o exam_system
```

**Using Provided Scripts:**

**Windows:**
```bash
compile_and_run.bat
```

**Linux/Mac:**
```bash
chmod +x compile_and_run.sh
./compile_and_run.sh
```

### Running the Program

```bash
./exam_system          # Linux/Mac
exam_system.exe        # Windows
```

### First Run

- Program loads data silently in background
- If data files don't exist, starts with empty vectors
- Admin can immediately start adding students and creating exams

---

## 📖 Usage Guide

### Admin Guide

**Login Credentials:**
```
Username: admin
Password: admin123
```

**Adding Students:**
1. Select "Add Student"
2. Enter unique Student ID
3. Enter full name, department, password
4. Enter registration date
5. Student added to vector automatically

**Creating Exams:**
1. Select "Create Exam"
2. Enter unique Exam ID, course name, duration
3. Select "Add Question to Exam"
4. Add unlimited questions (vector grows automatically)
5. Set exam status to ACTIVE

**Viewing Results:**
- Select "View All Results"
- See all student exam results
- Results show score, percentage, grade, pass/fail status

**Saving Data:**
- Select "Save Data" anytime
- Or exit program (auto-saves)
- Confirmation shows: "Students: X | Exams: Y | Results: Z"

### Student Guide

**Login:**
1. Select "Student Login"
2. Enter your Student ID
3. Enter your password
4. Access granted to student panel

**Taking Exams:**
1. Select "View Available Exams"
2. Note the Exam ID you want to take
3. Select "Take Exam"
4. Enter Exam ID
5. Answer each question (A/B/C/D)
6. **See results immediately after completion:**
   - Your score (e.g., 30/30)
   - Percentage (e.g., 100.00%)
   - Grade (A, B, C, D, or F)
   - Status (PASSED or FAILED)

**Viewing Results:**
1. Select "View My Results"
2. See all your exam results
3. Each result shows detailed metrics

---

## 📁 File Structure

```
FOP_project/
│
├── main.cpp                 # Program entry point, menu system
├── student.h                # Student and Date class declarations
├── student.cpp              # Student and Date class implementations
├── exam.h                   # Exam and Question class declarations
├── exam.cpp                 # Exam and Question class implementations
├── result.h                 # Result class declaration
├── result.cpp               # Result class implementation
├── filemanager.h            # File I/O function declarations
├── filemanager.cpp          # File I/O implementations
├── utility.h                # Template functions and utilities
├── utility.cpp              # Utility function implementations
│
├── students.txt             # Student data file (auto-generated)
├── exams.txt                # Exam data file (auto-generated)
├── results.txt              # Result data file (auto-generated)
│
├── compile_and_run.bat      # Windows compilation script
├── compile_and_run.sh       # Linux/Mac compilation script
├── README.md                # This file
└── LICENSE                  # License information
```

---

## 💾 Data Management

### Data Files

**students.txt:**
- Stores all student records
- Professional labeled format
- Includes ID, name, department, password, registration date

**exams.txt:**
- Stores all exams and their questions
- Each exam includes all question details
- Question format: text, options A-D, correct answer, marks

**results.txt:**
- Stores all exam results
- Includes student ID, exam ID, score, percentage, grade, status

### Data Persistence

- **Auto-load:** Data loaded silently on program startup
- **Auto-save:** Data saved automatically on program exit
- **Manual save:** Admin can save anytime from menu
- **Vector-based:** All data stored in dynamic vectors
- **No limits:** Unlimited students, exams, questions, results

---

## 🔧 Technical Specifications

### Language & Standards
- **Language:** C++
- **Standard:** C++11 (minimum)
- **STL:** Vector container
- **Paradigm:** Object-Oriented Programming

### Data Structures
- **Primary:** `vector<T>` for all collections
- **Classes:** 5 main classes (Date, Student, Question, Exam, Result)
- **Enums:** 2 enumerations (ExamStatus, UserRole)

### Capacity
- **Students:** Unlimited (vector-based)
- **Exams:** Unlimited (vector-based)
- **Questions per Exam:** Unlimited (vector-based)
- **Results:** Unlimited (vector-based)

### Features
- ✅ Class-based design with encapsulation
- ✅ Demonstrates both class and struct concepts (uses class with explicit access specifiers)
- ✅ STL vector for dynamic storage
- ✅ Constructors (default and parameterized)
- ✅ Getter/Setter methods
- ✅ Const correctness
- ✅ Template functions
- ✅ File I/O with vectors
- ✅ Enum for type safety
- ✅ Typedef for clean code
- ✅ Modular architecture
- ✅ Role-based access control
- ✅ Instant result feedback
- ✅ Professional file formatting
- ✅ Silent background loading
- ✅ Clean console interface
- ✅ Features shown on main menu (before login)

---

## 📊 Key Improvements from Array-Based Version

| Feature | Array Version | Vector Version |
|---------|--------------|----------------|
| **Capacity** | Fixed (100 students, 50 exams) | Unlimited (dynamic growth) |
| **Memory** | Pre-allocated (wasted if unused) | Allocated as needed |
| **Count Tracking** | Manual (`studentCount` variable) | Automatic (`.size()` method) |
| **Adding** | `students[count++] = newStudent` | `students.push_back(newStudent)` |
| **Deleting** | Manual shifting of elements | `students.erase(students.begin() + i)` |
| **Checking Full** | `if (count >= MAX)` | Never full (grows automatically) |
| **Iteration** | `for (int i = 0; i < count; i++)` | `for (size_t i = 0; i < students.size(); i++)` |
| **Clearing** | `count = 0` (data still in memory) | `students.clear()` (memory freed) |

---

## 🎓 Learning Outcomes

After studying this project, you will understand:

1. **Object-Oriented Programming**
   - Class design and implementation
   - Encapsulation and data hiding
   - Constructors and destructors
   - Accessor methods (getters/setters)

2. **STL Containers**
   - Vector usage and operations
   - Dynamic memory management
   - Iterator concepts
   - Container methods

3. **Modern C++ Practices**
   - Const correctness
   - Pass by reference
   - Template functions
   - Type aliases (typedef)

4. **Software Design**
   - Modular architecture
   - Separation of concerns
   - Code reusability
   - Maintainability

5. **Real-World Application**
   - File I/O operations
   - Data persistence
   - User authentication
   - Role-based access control
   - Menu-driven interfaces

---

## 📝 Notes

- **Admin credentials are hardcoded** for simplicity (username: admin, password: admin123)
- **File loading is silent** - no console output during startup
- **Main menu shows features** - Admin and Student capabilities visible before login
- **Data auto-saves** on program exit
- **Results are instant** - students see scores immediately after exam
- **No capacity limits** - vectors grow dynamically
- **Professional formatting** - all output is clean and organized
- **Cross-platform** - works on Windows, Linux, and macOS
- **Uses classes** - Demonstrates OOP with explicit private/public sections (class and struct are interchangeable in C++)

---

## 🤝 Contributing

This is an academic project. For improvements or suggestions:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

---

## 📄 License

This project is created for academic purposes. See LICENSE file for details.

---

## 👨‍💻 Authors

**Addis Ababa Science and Technology University**  
**College of Engineering**  
**Department of Software Engineering**  
*Fundamentals of Programming Course*  
*Section D - Group 5*

**Group Members:**
1. Abraham Amogne (ETS1848/17)
2. Saron Anbesaw (ETS1309/17)
3. Seble Sisay (ETS1314/17)
4. Senet Anbesaw (ETS1332/17)
5. Shanble Dires (ETS1336/17)
6. Zeynu Aman (ETS1622/17)

---

<div align="center">

**⭐ If this project helped you learn C++, please give it a star! ⭐**

</div>
