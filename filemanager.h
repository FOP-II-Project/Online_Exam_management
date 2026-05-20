#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "student.h"
#include "exam.h"
#include "result.h"

// File names
const string STUDENTS_FILE = "students.txt";
const string EXAMS_FILE = "exams.txt";
const string RESULTS_FILE = "results.txt";

// Record separator for professional formatting
const string RECORD_SEPARATOR = "----------------------------------------";

// Student file operations
void saveStudentsToFile(const StudentType students[], int studentCount);
void loadStudentsFromFile(StudentType students[], int &studentCount);

// Exam file operations
void saveExamsToFile(const ExamType exams[], int examCount);
void loadExamsFromFile(ExamType exams[], int &examCount);

// Result file operations
void saveResultsToFile(const ResultType results[], int resultCount);
void loadResultsFromFile(ResultType results[], int &resultCount);

#endif
