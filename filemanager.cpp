#include "filemanager.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Save students to file using vector
void saveStudentsToFile(const vector<StudentType> &students) {
    ofstream outFile(STUDENTS_FILE);
    
    if (!outFile) {
        cout << "Error: Could not open " << STUDENTS_FILE << " for writing!" << endl;
        return;
    }
    
    outFile << "STUDENT RECORDS DATABASE" << endl;
    outFile << "Total Students: " << students.size() << endl;
    outFile << "========================================" << endl << endl;
    
    for (size_t i = 0; i < students.size(); i++) {
        outFile << RECORD_SEPARATOR << endl;
        outFile << "Student ID   : " << students[i].getStudentId() << endl;
        outFile << "Name         : " << students[i].getFullName() << endl;
        outFile << "Department   : " << students[i].getDepartment() << endl;
        outFile << "Password     : " << students[i].getPassword() << endl;
        
        DateType regDate = students[i].getRegistrationDate();
        outFile << "Reg. Date    : " 
                << setfill('0') << setw(2) << regDate.getDay() << "/"
                << setfill('0') << setw(2) << regDate.getMonth() << "/"
                << regDate.getYear() << endl;
        outFile << RECORD_SEPARATOR << endl << endl;
    }
    
    outFile.close();
}

// Load students from file using vector
void loadStudentsFromFile(vector<StudentType> &students) {
    ifstream inFile(STUDENTS_FILE);
    
    if (!inFile) {
        students.clear();
        return;
    }
    
    string line;
    int studentCount = 0;
    
    getline(inFile, line);
    getline(inFile, line);
    
    size_t pos = line.find(": ");
    if (pos != string::npos) {
        studentCount = stoi(line.substr(pos + 2));
    }
    
    getline(inFile, line);
    getline(inFile, line);
    
    students.clear();
    
    for (int i = 0; i < studentCount; i++) {
        StudentType tempStudent;
        
        getline(inFile, line);
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempStudent.setStudentId(line.substr(pos + 2));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempStudent.setFullName(line.substr(pos + 2));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempStudent.setDepartment(line.substr(pos + 2));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempStudent.setPassword(line.substr(pos + 2));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            string dateStr = line.substr(pos + 2);
            int day, month, year;
            sscanf(dateStr.c_str(), "%d/%d/%d", &day, &month, &year);
            DateType tempDate(day, month, year);
            tempStudent.setRegistrationDate(tempDate);
        }
        
        students.push_back(tempStudent);
        
        getline(inFile, line);
        getline(inFile, line);
    }
    
    inFile.close();
}

// Save exams to file using vector
void saveExamsToFile(const vector<ExamType> &exams) {
    ofstream outFile(EXAMS_FILE);
    
    if (!outFile) {
        cout << "Error: Could not open " << EXAMS_FILE << " for writing!" << endl;
        return;
    }
    
    outFile << "EXAM RECORDS DATABASE" << endl;
    outFile << "Total Exams: " << exams.size() << endl;
    outFile << "========================================" << endl << endl;
    
    for (size_t i = 0; i < exams.size(); i++) {
        outFile << RECORD_SEPARATOR << endl;
        outFile << "Exam ID      : " << exams[i].getExamId() << endl;
        outFile << "Course Name  : " << exams[i].getCourseName() << endl;
        outFile << "Duration     : " << exams[i].getDurationMinutes() << " minutes" << endl;
        outFile << "Questions    : " << exams[i].getTotalQuestions() << endl;
        outFile << "Status       : " << (int)exams[i].getStatus() << endl;
        outFile << RECORD_SEPARATOR << endl << endl;
        
        for (int j = 0; j < exams[i].getTotalQuestions(); j++) {
            QuestionType q = exams[i].getQuestion(j);
            
            outFile << "  Question " << (j + 1) << ":" << endl;
            outFile << "  ----------------------------------------" << endl;
            outFile << "  Question ID  : " << q.getQuestionId() << endl;
            outFile << "  Question     : " << q.getQuestionText() << endl;
            outFile << "  Option A     : " << q.getOptionA() << endl;
            outFile << "  Option B     : " << q.getOptionB() << endl;
            outFile << "  Option C     : " << q.getOptionC() << endl;
            outFile << "  Option D     : " << q.getOptionD() << endl;
            outFile << "  Correct Ans  : " << q.getCorrectAnswer() << endl;
            outFile << "  Marks        : " << q.getMark() << endl;
            outFile << "  ----------------------------------------" << endl << endl;
        }
    }
    
    outFile.close();
}

// Load exams from file using vector
void loadExamsFromFile(vector<ExamType> &exams) {
    ifstream inFile(EXAMS_FILE);
    
    if (!inFile) {
        exams.clear();
        return;
    }
    
    string line;
    int examCount = 0;
    
    getline(inFile, line);
    getline(inFile, line);
    
    size_t pos = line.find(": ");
    if (pos != string::npos) {
        examCount = stoi(line.substr(pos + 2));
    }
    
    getline(inFile, line);
    getline(inFile, line);
    
    exams.clear();
    
    for (int i = 0; i < examCount; i++) {
        ExamType tempExam;
        
        getline(inFile, line);
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempExam.setExamId(stoi(line.substr(pos + 2)));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempExam.setCourseName(line.substr(pos + 2));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        int totalQuestions = 0;
        if (pos != string::npos) {
            tempExam.setDurationMinutes(stoi(line.substr(pos + 2)));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            totalQuestions = stoi(line.substr(pos + 2));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempExam.setStatus((ExamStatusType)stoi(line.substr(pos + 2)));
        }
        
        getline(inFile, line);
        getline(inFile, line);
        
        for (int j = 0; j < totalQuestions; j++) {
            QuestionType tempQuestion;
            
            getline(inFile, line);
            getline(inFile, line);
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setQuestionId(stoi(line.substr(pos + 2)));
            }
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setQuestionText(line.substr(pos + 2));
            }
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setOptionA(line.substr(pos + 2));
            }
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setOptionB(line.substr(pos + 2));
            }
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setOptionC(line.substr(pos + 2));
            }
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setOptionD(line.substr(pos + 2));
            }
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setCorrectAnswer(line.substr(pos + 2)[0]);
            }
            
            getline(inFile, line);
            pos = line.find(": ");
            if (pos != string::npos) {
                tempQuestion.setMark(stoi(line.substr(pos + 2)));
            }
            
            tempExam.addQuestion(tempQuestion);
            
            getline(inFile, line);
            getline(inFile, line);
        }
        
        exams.push_back(tempExam);
    }
    
    inFile.close();
}

// Save results to file using vector
void saveResultsToFile(const vector<ResultType> &results) {
    ofstream outFile(RESULTS_FILE);
    
    if (!outFile) {
        cout << "Error: Could not open " << RESULTS_FILE << " for writing!" << endl;
        return;
    }
    
    outFile << "RESULT RECORDS DATABASE" << endl;
    outFile << "Total Results: " << results.size() << endl;
    outFile << "========================================" << endl << endl;
    
    for (size_t i = 0; i < results.size(); i++) {
        outFile << RECORD_SEPARATOR << endl;
        outFile << "Student ID   : " << results[i].getStudentId() << endl;
        outFile << "Exam ID      : " << results[i].getExamId() << endl;
        outFile << "Score        : " << results[i].getScore() << " / " << results[i].getTotalMarks() << endl;
        outFile << "Percentage   : " << fixed << setprecision(2) << results[i].getPercentage() << "%" << endl;
        outFile << "Grade        : " << results[i].getGrade() << endl;
        outFile << "Status       : " << (results[i].isPassed() ? "PASS" : "FAIL") << endl;
        outFile << RECORD_SEPARATOR << endl << endl;
    }
    
    outFile.close();
}

// Load results from file using vector
void loadResultsFromFile(vector<ResultType> &results) {
    ifstream inFile(RESULTS_FILE);
    
    if (!inFile) {
        results.clear();
        return;
    }
    
    string line;
    int resultCount = 0;
    
    getline(inFile, line);
    getline(inFile, line);
    
    size_t pos = line.find(": ");
    if (pos != string::npos) {
        resultCount = stoi(line.substr(pos + 2));
    }
    
    getline(inFile, line);
    getline(inFile, line);
    
    results.clear();
    
    for (int i = 0; i < resultCount; i++) {
        ResultType tempResult;
        
        getline(inFile, line);
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempResult.setStudentId(line.substr(pos + 2));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempResult.setExamId(stoi(line.substr(pos + 2)));
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            string scoreStr = line.substr(pos + 2);
            int score, totalMarks;
            sscanf(scoreStr.c_str(), "%d / %d", &score, &totalMarks);
            tempResult.setScore(score);
            tempResult.setTotalMarks(totalMarks);
        }
        
        getline(inFile, line);
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            tempResult.setGrade(line.substr(pos + 2)[0]);
        }
        
        getline(inFile, line);
        pos = line.find(": ");
        if (pos != string::npos) {
            string status = line.substr(pos + 2);
            tempResult.setPassed(status == "PASS");
        }
        
        results.push_back(tempResult);
        
        getline(inFile, line);
        getline(inFile, line);
    }
    
    inFile.close();
}
