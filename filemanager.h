#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "student.h"
#include "exam.h"
#include "result.h"

// File names
const string STUDENTS_FILE = "students.txt";
const string EXAMS_FILE = "exams.txt";
const string RESULTS_FILE = "results.txt";
const string RECORD_SEPARATOR = "----------------------------------------";

// File operations using vector (STL)
void saveStudentsToFile(const vector<StudentType> &students);
void loadStudentsFromFile(vector<StudentType> &students);

void saveExamsToFile(const vector<ExamType> &exams);
void loadExamsFromFile(vector<ExamType> &exams);

void saveResultsToFile(const vector<ResultType> &results);
void loadResultsFromFile(vector<ResultType> &results);

#endif
