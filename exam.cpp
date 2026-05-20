#include "exam.h"
#include "result.h"
#include "utility.h"
#include <iostream>
using namespace std;

// ============================================================
// FUNCTION: createExam
// ============================================================
// PURPOSE: Create a new exam in the system
// PARAMETERS:
// - exams[]: array storing all exam records
// - examCount: current number of exams (passed by reference)
// RETURN: void
// LOGIC:
// 1. Check if array is full
// 2. Accept exam details from admin
// 3. Initialize exam with 0 questions
// 4. Store in array
// 5. Increment examCount
// CONCEPTS USED:
// - Arrays of structures
// - Pass by reference
// - Input validation
// - Enum (ExamStatus)
// WHY NEEDED: Allows admin to create new exams
// INTERACTION: Called from admin menu
// ============================================================
void createExam(ExamType exams[], int &examCount) {
    clearScreen();
    displayHeader("CREATE NEW EXAM");
    
    if (examCount >= MAX_EXAMS) {
        cout << "Error: Maximum exam limit reached!" << endl;
        pauseSystem();
        return;
    }
    
    ExamType newExam;
    
    cout << "Enter Exam ID: ";
    cin >> newExam.examId;
    cin.ignore();
    
    if (!validatePositiveInt(newExam.examId)) {
        cout << "Error: Exam ID must be positive!" << endl;
        pauseSystem();
        return;
    }
    
    // Check for duplicate exam ID
    if (searchExam(exams, examCount, newExam.examId) != -1) {
        cout << "Error: Exam ID already exists!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "Enter Course Name: ";
    getline(cin, newExam.courseName);
    
    cout << "Enter Duration (minutes): ";
    cin >> newExam.durationMinutes;
    
    if (!validatePositiveInt(newExam.durationMinutes)) {
        cout << "Error: Duration must be positive!" << endl;
        pauseSystem();
        return;
    }
    
    // Initialize exam
    newExam.totalQuestions = 0;
    newExam.status = ACTIVE;  // Using enum value
    
    exams[examCount] = newExam;
    examCount++;
    
    cout << "\nExam created successfully!" << endl;
    cout << "Total exams: " << examCount << endl;
    cout << "Now you can add questions to this exam." << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: addQuestion
// ============================================================
// PURPOSE: Add a question to an existing exam
// PARAMETERS:
// - exams[]: array of exams
// - examCount: total number of exams
// RETURN: void
// LOGIC:
// 1. Accept exam ID
// 2. Search for exam
// 3. Check if exam can hold more questions
// 4. Accept question details
// 5. Add question to exam's question array
// 6. Increment totalQuestions
// CONCEPTS USED:
// - Arrays of structures
// - Nested arrays (questions inside exam)
// - Input validation
// WHY NEEDED: Populates exams with questions
// INTERACTION: Called from admin menu
// ============================================================
void addQuestion(ExamType exams[], int examCount) {
    clearScreen();
    displayHeader("ADD QUESTION TO EXAM");
    
    if (examCount == 0) {
        cout << "No exams available. Create an exam first." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    cout << "Enter Exam ID: ";
    cin >> examId;
    cin.ignore();
    
    int examIndex = searchExam(exams, examCount, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    ExamType &exam = exams[examIndex];
    
    if (exam.totalQuestions >= MAX_QUESTIONS_PER_EXAM) {
        cout << "Error: Maximum questions limit reached for this exam!" << endl;
        pauseSystem();
        return;
    }
    
    QuestionType newQuestion;
    
    cout << "\nExam: " << exam.courseName << endl;
    cout << "Current Questions: " << exam.totalQuestions << endl;
    displayLine();
    
    newQuestion.questionId = exam.totalQuestions + 1;
    
    cout << "\nEnter Question Text: ";
    getline(cin, newQuestion.questionText);
    
    cout << "Enter Option A: ";
    getline(cin, newQuestion.optionA);
    
    cout << "Enter Option B: ";
    getline(cin, newQuestion.optionB);
    
    cout << "Enter Option C: ";
    getline(cin, newQuestion.optionC);
    
    cout << "Enter Option D: ";
    getline(cin, newQuestion.optionD);
    
    cout << "Enter Correct Answer (A/B/C/D): ";
    cin >> newQuestion.correctAnswer;
    
    // Convert to uppercase
    if (newQuestion.correctAnswer >= 'a' && newQuestion.correctAnswer <= 'd') {
        newQuestion.correctAnswer = newQuestion.correctAnswer - 32;
    }
    
    // Validate correct answer
    if (newQuestion.correctAnswer < 'A' || newQuestion.correctAnswer > 'D') {
        cout << "Error: Correct answer must be A, B, C, or D!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "Enter Marks for this Question: ";
    cin >> newQuestion.mark;
    
    if (!validatePositiveInt(newQuestion.mark)) {
        cout << "Error: Marks must be positive!" << endl;
        pauseSystem();
        return;
    }
    
    // Add question to exam
    exam.questions[exam.totalQuestions] = newQuestion;
    exam.totalQuestions++;
    
    cout << "\nQuestion added successfully!" << endl;
    cout << "Total questions in this exam: " << exam.totalQuestions << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: displayExams
// ============================================================
// PURPOSE: Display all exams in the system
// PARAMETERS:
// - exams[]: array of exams
// - examCount: number of exams
// RETURN: void
// LOGIC:
// 1. Check if any exams exist
// 2. Loop through exam array
// 3. Display each exam's details
// CONCEPTS USED:
// - Arrays of structures
// - For loop
// - Enum display
// WHY NEEDED: Allows viewing all available exams
// INTERACTION: Called from admin and student menus
// ============================================================
void displayExams(const ExamType exams[], int examCount) {
    clearScreen();
    displayHeader("ALL EXAMS");
    
    if (examCount == 0) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    for (int i = 0; i < examCount; i++) {
        cout << "\n--- Exam " << (i + 1) << " ---" << endl;
        displayExamDetails(exams[i]);
        displayLine();
    }
    
    cout << "\nTotal Exams: " << examCount << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: displayExamDetails
// ============================================================
// PURPOSE: Display detailed information of a single exam
// PARAMETERS:
// - exam: exam record to display
// RETURN: void
// LOGIC: Display all fields including status enum
// CONCEPTS USED:
// - Structure member access
// - Enum to string conversion
// WHY NEEDED: Reusable display function
// INTERACTION: Called by displayExams and other functions
// ============================================================
void displayExamDetails(const ExamType &exam) {
    cout << "Exam ID: " << exam.examId << endl;
    cout << "Course: " << exam.courseName << endl;
    cout << "Duration: " << exam.durationMinutes << " minutes" << endl;
    cout << "Total Questions: " << exam.totalQuestions << endl;
    
    // Display enum status
    cout << "Status: ";
    switch (exam.status) {
        case ACTIVE:
            cout << "Active";
            break;
        case INACTIVE:
            cout << "Inactive";
            break;
        case COMPLETED:
            cout << "Completed";
            break;
    }
    cout << endl;
}

// ============================================================
// FUNCTION: searchExam
// ============================================================
// PURPOSE: Search for an exam by ID
// PARAMETERS:
// - exams[]: array to search
// - examCount: number of exams
// - examId: ID to search for
// RETURN: index if found, -1 if not found
// LOGIC:
// 1. Loop through exam array
// 2. Compare each exam's ID with search key
// 3. Return index if match found
// CONCEPTS USED:
// - Linear search algorithm
// - Arrays of structures
// WHY NEEDED: Required for adding questions and taking exams
// INTERACTION: Used by multiple functions
// ============================================================
int searchExam(const ExamType exams[], int examCount, int examId) {
    for (int i = 0; i < examCount; i++) {
        if (exams[i].examId == examId) {
            return i;
        }
    }
    return -1;
}

// ============================================================
// FUNCTION: takeExam
// ============================================================
// PURPOSE: Allow student to take an exam
// PARAMETERS:
// - exams[]: array of exams
// - examCount: total exams
// - studentId: ID of student taking exam
// - results[]: array to store result
// - resultCount: total results (by reference)
// RETURN: void
// LOGIC:
// 1. Display available exams
// 2. Accept exam selection
// 3. Display questions one by one
// 4. Accept student's answers
// 5. Calculate score
// 6. Store result
// CONCEPTS USED:
// - Arrays of structures
// - Nested loops (questions inside exam)
// - Score calculation
// - Result generation
// WHY NEEDED: Core functionality for students
// INTERACTION: Called from student menu, creates result record
// ============================================================
void takeExam(const ExamType exams[], int examCount, int studentId, 
              ResultType results[], int &resultCount) {
    clearScreen();
    displayHeader("TAKE EXAM");
    
    if (examCount == 0) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    // Check if results array is full
    if (resultCount >= MAX_RESULTS) {
        cout << "Error: Maximum results limit reached!" << endl;
        pauseSystem();
        return;
    }
    
    // Display available exams
    cout << "Available Exams:" << endl;
    displayLine();
    for (int i = 0; i < examCount; i++) {
        if (exams[i].status == ACTIVE && exams[i].totalQuestions > 0) {
            cout << "Exam ID: " << exams[i].examId 
                 << " | Course: " << exams[i].courseName 
                 << " | Questions: " << exams[i].totalQuestions << endl;
        }
    }
    displayLine();
    
    int examId;
    cout << "\nEnter Exam ID to take: ";
    cin >> examId;
    
    int examIndex = searchExam(exams, examCount, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    const ExamType &exam = exams[examIndex];
    
    if (exam.status != ACTIVE) {
        cout << "This exam is not active!" << endl;
        pauseSystem();
        return;
    }
    
    if (exam.totalQuestions == 0) {
        cout << "This exam has no questions!" << endl;
        pauseSystem();
        return;
    }
    
    // Check if student already took this exam
    if (searchResult(results, resultCount, studentId, examId) != -1) {
        cout << "You have already taken this exam!" << endl;
        cout << "View your results from the main menu." << endl;
        pauseSystem();
        return;
    }
    
    clearScreen();
    displayHeader(exam.courseName);
    cout << "Duration: " << exam.durationMinutes << " minutes" << endl;
    cout << "Total Questions: " << exam.totalQuestions << endl;
    cout << "\nPress Enter to start...";
    cin.ignore();
    cin.get();
    
    int score = 0;
    int totalMarks = 0;
    
    // Loop through all questions
    for (int i = 0; i < exam.totalQuestions; i++) {
        clearScreen();
        const QuestionType &q = exam.questions[i];
        
        cout << "Question " << (i + 1) << " of " << exam.totalQuestions << endl;
        displayLine();
        cout << q.questionText << endl;
        cout << "\nA. " << q.optionA << endl;
        cout << "B. " << q.optionB << endl;
        cout << "C. " << q.optionC << endl;
        cout << "D. " << q.optionD << endl;
        cout << "\nMarks: " << q.mark << endl;
        displayLine();
        
        char answer;
        cout << "Your Answer (A/B/C/D): ";
        cin >> answer;
        
        // Convert to uppercase
        if (answer >= 'a' && answer <= 'd') {
            answer = answer - 32;
        }
        
        totalMarks += q.mark;
        
        if (answer == q.correctAnswer) {
            score += q.mark;
        }
    }
    
    // Create result record
    ResultType newResult;
    newResult.studentId = studentId;
    newResult.examId = examId;
    newResult.score = score;
    newResult.totalMarks = totalMarks;
    newResult.grade = calculateGrade(score, totalMarks);
    newResult.passed = (score >= (totalMarks * 0.5));  // 50% passing criteria
    
    results[resultCount] = newResult;
    resultCount++;
    
    // Display result immediately
    clearScreen();
    displayHeader("EXAM COMPLETED");
    displayResult(newResult);
    pauseSystem();
}

// ============================================================
// FUNCTION: editQuestion
// ============================================================
// PURPOSE: Edit an existing question in an exam
// PARAMETERS:
// - exams[]: array of exams
// - examCount: total number of exams
// RETURN: void
// LOGIC:
// 1. Accept exam ID and question number
// 2. Search for exam
// 3. Validate question number
// 4. Display current question details
// 5. Accept new details
// 6. Update question
// CONCEPTS USED:
// - Arrays of structures
// - Nested arrays
// - Input validation
// WHY NEEDED: Allows admin to correct or update questions
// INTERACTION: Called from admin menu
// ============================================================
void editQuestion(ExamType exams[], int examCount) {
    clearScreen();
    displayHeader("EDIT QUESTION");
    
    if (examCount == 0) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    cout << "Enter Exam ID: ";
    cin >> examId;
    cin.ignore();
    
    int examIndex = searchExam(exams, examCount, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    ExamType &exam = exams[examIndex];
    
    if (exam.totalQuestions == 0) {
        cout << "This exam has no questions!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\nExam: " << exam.courseName << endl;
    cout << "Total Questions: " << exam.totalQuestions << endl;
    displayLine();
    
    int questionNum;
    cout << "\nEnter Question Number to Edit (1-" << exam.totalQuestions << "): ";
    cin >> questionNum;
    cin.ignore();
    
    if (questionNum < 1 || questionNum > exam.totalQuestions) {
        cout << "Invalid question number!" << endl;
        pauseSystem();
        return;
    }
    
    int qIndex = questionNum - 1;
    QuestionType &q = exam.questions[qIndex];
    
    // Display current question
    clearScreen();
    displayHeader("CURRENT QUESTION");
    cout << "Question: " << q.questionText << endl;
    cout << "A. " << q.optionA << endl;
    cout << "B. " << q.optionB << endl;
    cout << "C. " << q.optionC << endl;
    cout << "D. " << q.optionD << endl;
    cout << "Correct Answer: " << q.correctAnswer << endl;
    cout << "Marks: " << q.mark << endl;
    displayLine();
    
    cout << "\nEnter New Details (press Enter to keep current value):" << endl;
    displayLine();
    
    string input;
    
    cout << "\nNew Question Text: ";
    getline(cin, input);
    if (!input.empty()) {
        q.questionText = input;
    }
    
    cout << "New Option A: ";
    getline(cin, input);
    if (!input.empty()) {
        q.optionA = input;
    }
    
    cout << "New Option B: ";
    getline(cin, input);
    if (!input.empty()) {
        q.optionB = input;
    }
    
    cout << "New Option C: ";
    getline(cin, input);
    if (!input.empty()) {
        q.optionC = input;
    }
    
    cout << "New Option D: ";
    getline(cin, input);
    if (!input.empty()) {
        q.optionD = input;
    }
    
    cout << "New Correct Answer (A/B/C/D): ";
    getline(cin, input);
    if (!input.empty()) {
        char newAnswer = input[0];
        if (newAnswer >= 'a' && newAnswer <= 'd') {
            newAnswer = newAnswer - 32;
        }
        if (newAnswer >= 'A' && newAnswer <= 'D') {
            q.correctAnswer = newAnswer;
        } else {
            cout << "Invalid answer! Keeping current value." << endl;
        }
    }
    
    cout << "New Marks: ";
    getline(cin, input);
    if (!input.empty()) {
        int newMarks = atoi(input.c_str());
        if (validatePositiveInt(newMarks)) {
            q.mark = newMarks;
        } else {
            cout << "Invalid marks! Keeping current value." << endl;
        }
    }
    
    cout << "\nQuestion updated successfully!" << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: deleteQuestion
// ============================================================
// PURPOSE: Delete a question from an exam
// PARAMETERS:
// - exams[]: array of exams
// - examCount: total number of exams
// RETURN: void
// LOGIC:
// 1. Accept exam ID and question number
// 2. Search for exam
// 3. Validate question number
// 4. Display question to confirm
// 5. Shift remaining questions left
// 6. Decrement totalQuestions
// 7. Update question IDs
// CONCEPTS USED:
// - Arrays of structures
// - Array element deletion
// - Nested arrays
// WHY NEEDED: Allows admin to remove incorrect questions
// INTERACTION: Called from admin menu
// ============================================================
void deleteQuestion(ExamType exams[], int examCount) {
    clearScreen();
    displayHeader("DELETE QUESTION");
    
    if (examCount == 0) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    cout << "Enter Exam ID: ";
    cin >> examId;
    cin.ignore();
    
    int examIndex = searchExam(exams, examCount, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    ExamType &exam = exams[examIndex];
    
    if (exam.totalQuestions == 0) {
        cout << "This exam has no questions!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\nExam: " << exam.courseName << endl;
    cout << "Total Questions: " << exam.totalQuestions << endl;
    displayLine();
    
    int questionNum;
    cout << "\nEnter Question Number to Delete (1-" << exam.totalQuestions << "): ";
    cin >> questionNum;
    cin.ignore();
    
    if (questionNum < 1 || questionNum > exam.totalQuestions) {
        cout << "Invalid question number!" << endl;
        pauseSystem();
        return;
    }
    
    int qIndex = questionNum - 1;
    
    // Display question to confirm
    cout << "\nQuestion to Delete:" << endl;
    displayLine();
    cout << exam.questions[qIndex].questionText << endl;
    displayLine();
    
    cout << "\nAre you sure you want to delete this question? (Y/N): ";
    char confirm;
    cin >> confirm;
    cin.ignore();
    
    if (confirm != 'Y' && confirm != 'y') {
        cout << "Deletion cancelled." << endl;
        pauseSystem();
        return;
    }
    
    // Shift remaining questions left
    for (int i = qIndex; i < exam.totalQuestions - 1; i++) {
        exam.questions[i] = exam.questions[i + 1];
        exam.questions[i].questionId = i + 1;  // Update question ID
    }
    
    exam.totalQuestions--;
    
    cout << "\nQuestion deleted successfully!" << endl;
    cout << "Remaining questions: " << exam.totalQuestions << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: updateExam
// ============================================================
// PURPOSE: Update exam details (course name, duration)
// PARAMETERS:
// - exams[]: array of exams
// - examCount: total number of exams
// RETURN: void
// LOGIC:
// 1. Accept exam ID
// 2. Search for exam
// 3. Display current details
// 4. Accept new details
// 5. Update exam record
// CONCEPTS USED:
// - Arrays of structures
// - Input validation
// - Structure member update
// WHY NEEDED: Allows admin to modify exam information
// INTERACTION: Called from admin menu
// ============================================================
void updateExam(ExamType exams[], int examCount) {
    clearScreen();
    displayHeader("UPDATE EXAM");
    
    if (examCount == 0) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    cout << "Enter Exam ID to Update: ";
    cin >> examId;
    cin.ignore();
    
    int examIndex = searchExam(exams, examCount, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    ExamType &exam = exams[examIndex];
    
    // Display current details
    clearScreen();
    displayHeader("CURRENT EXAM DETAILS");
    displayExamDetails(exam);
    displayLine();
    
    cout << "\nEnter New Details (press Enter to keep current value):" << endl;
    displayLine();
    
    string input;
    
    cout << "\nNew Course Name: ";
    getline(cin, input);
    if (!input.empty()) {
        exam.courseName = input;
    }
    
    cout << "New Duration (minutes): ";
    getline(cin, input);
    if (!input.empty()) {
        int newDuration = atoi(input.c_str());
        if (validatePositiveInt(newDuration)) {
            exam.durationMinutes = newDuration;
        } else {
            cout << "Invalid duration! Keeping current value." << endl;
        }
    }
    
    cout << "New Status (0=Active, 1=Inactive, 2=Completed): ";
    getline(cin, input);
    if (!input.empty()) {
        int statusChoice = atoi(input.c_str());
        if (statusChoice >= 0 && statusChoice <= 2) {
            exam.status = static_cast<ExamStatusType>(statusChoice);
        } else {
            cout << "Invalid status! Keeping current value." << endl;
        }
    }
    
    cout << "\nExam updated successfully!" << endl;
    pauseSystem();
}

// ============================================================
// FUNCTION: deleteExam
// ============================================================
// PURPOSE: Delete an entire exam from the system
// PARAMETERS:
// - exams[]: array of exams
// - examCount: total number of exams (by reference)
// RETURN: void
// LOGIC:
// 1. Accept exam ID
// 2. Search for exam
// 3. Display exam details for confirmation
// 4. Shift remaining exams left
// 5. Decrement examCount
// CONCEPTS USED:
// - Arrays of structures
// - Array element deletion
// - Pass by reference
// WHY NEEDED: Allows admin to remove obsolete exams
// INTERACTION: Called from admin menu
// NOTE: Should also delete related results in production system
// ============================================================
void deleteExam(ExamType exams[], int &examCount) {
    clearScreen();
    displayHeader("DELETE EXAM");
    
    if (examCount == 0) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    cout << "Enter Exam ID to Delete: ";
    cin >> examId;
    cin.ignore();
    
    int examIndex = searchExam(exams, examCount, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    // Display exam details for confirmation
    cout << "\nExam to Delete:" << endl;
    displayLine();
    displayExamDetails(exams[examIndex]);
    displayLine();
    
    cout << "\nWARNING: This will delete the exam and all its questions!" << endl;
    cout << "Are you sure you want to delete this exam? (Y/N): ";
    char confirm;
    cin >> confirm;
    cin.ignore();
    
    if (confirm != 'Y' && confirm != 'y') {
        cout << "Deletion cancelled." << endl;
        pauseSystem();
        return;
    }
    
    // Shift remaining exams left
    for (int i = examIndex; i < examCount - 1; i++) {
        exams[i] = exams[i + 1];
    }
    
    examCount--;
    
    cout << "\nExam deleted successfully!" << endl;
    cout << "Remaining exams: " << examCount << endl;
    pauseSystem();
}
