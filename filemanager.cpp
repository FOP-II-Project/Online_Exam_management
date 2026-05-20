#include "filemanager.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Save all student records with professional formatting
void saveStudentsToFile(const StudentType students[], int studentCount) {
    ofstream outFile(STUDENTS_FILE);
    
    if (!outFile) {
        cout << "Error: Could not open " << STUDENTS_FILE << " for writing!" << endl;
        return;
    }
    
    // Write header
    outFile << "STUDENT RECORDS DATABASE" << endl;
    outFile << "Total Students: " << studentCount << endl;
    outFile << "========================================" << endl << endl;
    
    // Write each student record with professional formatting
    for (int i = 0; i < studentCount; i++) {
        outFile << RECORD_SEPARATOR << endl;
        outFile << "Student ID   : " << students[i].studentId << endl;
        outFile << "Name         : " << students[i].fullName << endl;
        outFile << "Department   : " << students[i].department << endl;
        outFile << "Password     : " << students[i].password << endl;
        outFile << "Reg. Date    : " 
                << setfill('0') << setw(2) << students[i].registrationDate.day << "/"
                << setfill('0') << setw(2) << students[i].registrationDate.month << "/"
                << students[i].registrationDate.year << endl;
        outFile << RECORD_SEPARATOR << endl << endl;
    }
    
    outFile.close();
    cout << "Students saved successfully to " << STUDENTS_FILE << endl;
}

// Load all student records from file
void loadStudentsFromFile(StudentType students[], int &studentCount) {
    ifstream inFile(STUDENTS_FILE);
    
    if (!inFile) {
        cout << "Note: " << STUDENTS_FILE << " not found. Starting with empty data." << endl;
        studentCount = 0;
        return;
    }
    
    string line;
    
    // Skip header lines
    getline(inFile, line); // "STUDENT RECORDS DATABASE"
    getline(inFile, line); // "Total Students: X"
    
    // Extract count from header
    size_t pos = line.find(": ");
    if (pos != string::npos) {
        studentCount = stoi(line.substr(pos + 2));
    }
    
    getline(inFile, line); // "========"
    getline(inFile, line); // Empty line
    
    // Read each student record
    for (int i = 0; i < studentCount; i++) {
        getline(inFile, line); // Separator
        
        // Read Student ID
        getline(inFile, line);
        pos = line.find(": ");
        students[i].studentId = stoi(line.substr(pos + 2));
        
        // Read Name
        getline(inFile, line);
        pos = line.find(": ");
        students[i].fullName = line.substr(pos + 2);
        
        // Read Department
        getline(inFile, line);
        pos = line.find(": ");
        students[i].department = line.substr(pos + 2);
        
        // Read Password
        getline(inFile, line);
        pos = line.find(": ");
        students[i].password = line.substr(pos + 2);
        
        // Read Registration Date
        getline(inFile, line);
        pos = line.find(": ");
        string dateStr = line.substr(pos + 2);
        sscanf(dateStr.c_str(), "%d/%d/%d", 
               &students[i].registrationDate.day,
               &students[i].registrationDate.month,
               &students[i].registrationDate.year);
        
        getline(inFile, line); // Separator
        getline(inFile, line); // Empty line
    }
    
    inFile.close();
    cout << "Loaded " << studentCount << " students from " << STUDENTS_FILE << endl;
}

// Save all exam records with professional formatting
void saveExamsToFile(const ExamType exams[], int examCount) {
    ofstream outFile(EXAMS_FILE);
    
    if (!outFile) {
        cout << "Error: Could not open " << EXAMS_FILE << " for writing!" << endl;
        return;
    }
    
    // Write header
    outFile << "EXAM RECORDS DATABASE" << endl;
    outFile << "Total Exams: " << examCount << endl;
    outFile << "========================================" << endl << endl;
    
    // Write each exam record
    for (int i = 0; i < examCount; i++) {
        outFile << RECORD_SEPARATOR << endl;
        outFile << "Exam ID      : " << exams[i].examId << endl;
        outFile << "Course Name  : " << exams[i].courseName << endl;
        outFile << "Duration     : " << exams[i].durationMinutes << " minutes" << endl;
        outFile << "Questions    : " << exams[i].totalQuestions << endl;
        outFile << "Status       : " << (int)exams[i].status << endl;
        outFile << RECORD_SEPARATOR << endl << endl;
        
        // Write all questions for this exam
        for (int j = 0; j < exams[i].totalQuestions; j++) {
            const QuestionType &q = exams[i].questions[j];
            
            outFile << "  Question " << (j + 1) << ":" << endl;
            outFile << "  ----------------------------------------" << endl;
            outFile << "  Question ID  : " << q.questionId << endl;
            outFile << "  Question     : " << q.questionText << endl;
            outFile << "  Option A     : " << q.optionA << endl;
            outFile << "  Option B     : " << q.optionB << endl;
            outFile << "  Option C     : " << q.optionC << endl;
            outFile << "  Option D     : " << q.optionD << endl;
            outFile << "  Correct Ans  : " << q.correctAnswer << endl;
            outFile << "  Marks        : " << q.mark << endl;
            outFile << "  ----------------------------------------" << endl << endl;
        }
    }
    
    outFile.close();
    cout << "Exams saved successfully to " << EXAMS_FILE << endl;
}

// Load all exam records from file
void loadExamsFromFile(ExamType exams[], int &examCount) {
    ifstream inFile(EXAMS_FILE);
    
    if (!inFile) {
        cout << "Note: " << EXAMS_FILE << " not found. Starting with empty data." << endl;
        examCount = 0;
        return;
    }
    
    string line;
    
    // Skip header lines
    getline(inFile, line); // "EXAM RECORDS DATABASE"
    getline(inFile, line); // "Total Exams: X"
    
    // Extract count
    size_t pos = line.find(": ");
    if (pos != string::npos) {
        examCount = stoi(line.substr(pos + 2));
    }
    
    getline(inFile, line); // "========"
    getline(inFile, line); // Empty line
    
    // Read each exam record
    for (int i = 0; i < examCount; i++) {
        getline(inFile, line); // Separator
        
        // Read Exam ID
        getline(inFile, line);
        pos = line.find(": ");
        exams[i].examId = stoi(line.substr(pos + 2));
        
        // Read Course Name
        getline(inFile, line);
        pos = line.find(": ");
        exams[i].courseName = line.substr(pos + 2);
        
        // Read Duration
        getline(inFile, line);
        pos = line.find(": ");
        exams[i].durationMinutes = stoi(line.substr(pos + 2));
        
        // Read Total Questions
        getline(inFile, line);
        pos = line.find(": ");
        exams[i].totalQuestions = stoi(line.substr(pos + 2));
        
        // Read Status
        getline(inFile, line);
        pos = line.find(": ");
        exams[i].status = (ExamStatusType)stoi(line.substr(pos + 2));
        
        getline(inFile, line); // Separator
        getline(inFile, line); // Empty line
        
        // Read all questions for this exam
        for (int j = 0; j < exams[i].totalQuestions; j++) {
            QuestionType &q = exams[i].questions[j];
            
            getline(inFile, line); // "Question X:"
            getline(inFile, line); // Separator
            
            // Read Question ID
            getline(inFile, line);
            pos = line.find(": ");
            q.questionId = stoi(line.substr(pos + 2));
            
            // Read Question Text
            getline(inFile, line);
            pos = line.find(": ");
            q.questionText = line.substr(pos + 2);
            
            // Read Option A
            getline(inFile, line);
            pos = line.find(": ");
            q.optionA = line.substr(pos + 2);
            
            // Read Option B
            getline(inFile, line);
            pos = line.find(": ");
            q.optionB = line.substr(pos + 2);
            
            // Read Option C
            getline(inFile, line);
            pos = line.find(": ");
            q.optionC = line.substr(pos + 2);
            
            // Read Option D
            getline(inFile, line);
            pos = line.find(": ");
            q.optionD = line.substr(pos + 2);
            
            // Read Correct Answer
            getline(inFile, line);
            pos = line.find(": ");
            q.correctAnswer = line.substr(pos + 2)[0];
            
            // Read Marks
            getline(inFile, line);
            pos = line.find(": ");
            q.mark = stoi(line.substr(pos + 2));
            
            getline(inFile, line); // Separator
            getline(inFile, line); // Empty line
        }
    }
    
    inFile.close();
    cout << "Loaded " << examCount << " exams from " << EXAMS_FILE << endl;
}

// Save all result records with professional formatting
void saveResultsToFile(const ResultType results[], int resultCount) {
    ofstream outFile(RESULTS_FILE);
    
    if (!outFile) {
        cout << "Error: Could not open " << RESULTS_FILE << " for writing!" << endl;
        return;
    }
    
    // Write header
    outFile << "RESULT RECORDS DATABASE" << endl;
    outFile << "Total Results: " << resultCount << endl;
    outFile << "========================================" << endl << endl;
    
    // Write each result record
    for (int i = 0; i < resultCount; i++) {
        outFile << RECORD_SEPARATOR << endl;
        outFile << "Student ID   : " << results[i].studentId << endl;
        outFile << "Exam ID      : " << results[i].examId << endl;
        outFile << "Score        : " << results[i].score << " / " << results[i].totalMarks << endl;
        
        // Calculate percentage
        float percentage = (float)results[i].score / results[i].totalMarks * 100;
        outFile << "Percentage   : " << fixed << setprecision(2) << percentage << "%" << endl;
        
        outFile << "Grade        : " << results[i].grade << endl;
        outFile << "Status       : " << (results[i].passed ? "PASS" : "FAIL") << endl;
        outFile << RECORD_SEPARATOR << endl << endl;
    }
    
    outFile.close();
    cout << "Results saved successfully to " << RESULTS_FILE << endl;
}

// Load all result records from file
void loadResultsFromFile(ResultType results[], int &resultCount) {
    ifstream inFile(RESULTS_FILE);
    
    if (!inFile) {
        cout << "Note: " << RESULTS_FILE << " not found. Starting with empty data." << endl;
        resultCount = 0;
        return;
    }
    
    string line;
    
    // Skip header lines
    getline(inFile, line); // "RESULT RECORDS DATABASE"
    getline(inFile, line); // "Total Results: X"
    
    // Extract count
    size_t pos = line.find(": ");
    if (pos != string::npos) {
        resultCount = stoi(line.substr(pos + 2));
    }
    
    getline(inFile, line); // "========"
    getline(inFile, line); // Empty line
    
    // Read each result record
    for (int i = 0; i < resultCount; i++) {
        getline(inFile, line); // Separator
        
        // Read Student ID
        getline(inFile, line);
        pos = line.find(": ");
        results[i].studentId = stoi(line.substr(pos + 2));
        
        // Read Exam ID
        getline(inFile, line);
        pos = line.find(": ");
        results[i].examId = stoi(line.substr(pos + 2));
        
        // Read Score
        getline(inFile, line);
        pos = line.find(": ");
        string scoreStr = line.substr(pos + 2);
        sscanf(scoreStr.c_str(), "%d / %d", &results[i].score, &results[i].totalMarks);
        
        // Skip Percentage line
        getline(inFile, line);
        
        // Read Grade
        getline(inFile, line);
        pos = line.find(": ");
        results[i].grade = line.substr(pos + 2)[0];
        
        // Read Status
        getline(inFile, line);
        pos = line.find(": ");
        string status = line.substr(pos + 2);
        results[i].passed = (status == "PASS");
        
        getline(inFile, line); // Separator
        getline(inFile, line); // Empty line
    }
    
    inFile.close();
    cout << "Loaded " << resultCount << " results from " << RESULTS_FILE << endl;
}
