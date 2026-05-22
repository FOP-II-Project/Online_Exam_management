#include "exam.h"
#include "result.h"
#include "utility.h"
#include "filemanager.h"
#include <iostream>
using namespace std;

// Question class implementation
Question::Question() {
    questionId = 0;
    questionText = "";
    optionA = "";
    optionB = "";
    optionC = "";
    optionD = "";
    correctAnswer = 'A';
    mark = 0;
}

Question::Question(int id, string text, string a, string b, string c, string d, char ans, int m) {
    questionId = id;
    questionText = text;
    optionA = a;
    optionB = b;
    optionC = c;
    optionD = d;
    correctAnswer = ans;
    mark = m;
}

int Question::getQuestionId() const { return questionId; }
string Question::getQuestionText() const { return questionText; }
string Question::getOptionA() const { return optionA; }
string Question::getOptionB() const { return optionB; }
string Question::getOptionC() const { return optionC; }
string Question::getOptionD() const { return optionD; }
char Question::getCorrectAnswer() const { return correctAnswer; }
int Question::getMark() const { return mark; }

void Question::setQuestionId(int id) { questionId = id; }
void Question::setQuestionText(string text) { questionText = text; }
void Question::setOptionA(string a) { optionA = a; }
void Question::setOptionB(string b) { optionB = b; }
void Question::setOptionC(string c) { optionC = c; }
void Question::setOptionD(string d) { optionD = d; }
void Question::setCorrectAnswer(char ans) { correctAnswer = ans; }
void Question::setMark(int m) { mark = m; }

void Question::inputQuestionData() {
    cin.ignore();
    
    while (true) {
        cout << "\nEnter Question Text: ";
        getline(cin, questionText);
        if (!questionText.empty()) break;
        cout << "Error: Question text cannot be empty!" << endl;
    }
    
    while (true) {
        cout << "Enter Option A: ";
        getline(cin, optionA);
        if (!optionA.empty()) break;
        cout << "Error: Option A cannot be empty!" << endl;
    }
    
    while (true) {
        cout << "Enter Option B: ";
        getline(cin, optionB);
        if (!optionB.empty()) break;
        cout << "Error: Option B cannot be empty!" << endl;
    }
    
    while (true) {
        cout << "Enter Option C: ";
        getline(cin, optionC);
        if (!optionC.empty()) break;
        cout << "Error: Option C cannot be empty!" << endl;
    }
    
    while (true) {
        cout << "Enter Option D: ";
        getline(cin, optionD);
        if (!optionD.empty()) break;
        cout << "Error: Option D cannot be empty!" << endl;
    }
    
    while (true) {
        cout << "Enter Correct Answer (A/B/C/D): ";
        cin >> correctAnswer;
        
        if (correctAnswer >= 'a' && correctAnswer <= 'd') {
            correctAnswer = correctAnswer - 32;
        }
        
        if (correctAnswer >= 'A' && correctAnswer <= 'D') {
            break;
        }
        
        cout << "Error: Please enter A, B, C, or D only!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    while (true) {
        cout << "Enter Marks for this Question: ";
        if (!(cin >> mark)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        if (mark > 0) {
            break;
        }
        
        cout << "Error: Marks must be positive!" << endl;
    }
}

void Question::displayQuestion() const {
    cout << questionText << endl;
    cout << "\nA. " << optionA << endl;
    cout << "B. " << optionB << endl;
    cout << "C. " << optionC << endl;
    cout << "D. " << optionD << endl;
    cout << "\nMarks: " << mark << endl;
}

bool Question::checkAnswer(char answer) const {
    if (answer >= 'a' && answer <= 'd') {
        answer = answer - 32;
    }
    return answer == correctAnswer;
}

// Exam class implementation
Exam::Exam() {
    examId = 0;
    courseName = "";
    durationMinutes = 0;
    status = ACTIVE;
}

Exam::Exam(int id, string course, int duration) {
    examId = id;
    courseName = course;
    durationMinutes = duration;
    status = ACTIVE;
}

int Exam::getExamId() const { return examId; }
string Exam::getCourseName() const { return courseName; }
int Exam::getDurationMinutes() const { return durationMinutes; }
int Exam::getTotalQuestions() const { return questions.size(); }
ExamStatusType Exam::getStatus() const { return status; }
QuestionType Exam::getQuestion(int index) const { return questions[index]; }

void Exam::setExamId(int id) { examId = id; }
void Exam::setCourseName(string course) { courseName = course; }
void Exam::setDurationMinutes(int duration) { durationMinutes = duration; }
void Exam::setStatus(ExamStatusType st) { status = st; }

void Exam::displayExamDetails() const {
    cout << "Exam ID: " << examId << endl;
    cout << "Course: " << courseName << endl;
    cout << "Duration: " << durationMinutes << " minutes" << endl;
    cout << "Total Questions: " << questions.size() << endl;
    cout << "Status: ";
    switch (status) {
        case ACTIVE: cout << "Active"; break;
        case INACTIVE: cout << "Inactive"; break;
        case COMPLETED: cout << "Completed"; break;
    }
    cout << endl;
}

void Exam::addQuestion(QuestionType q) {
    q.setQuestionId(questions.size() + 1);
    questions.push_back(q);
}

bool Exam::editQuestion(int questionNum) {
    if (questionNum < 1 || questionNum > (int)questions.size()) {
        return false;
    }
    
    int index = questionNum - 1;
    
    cout << "\n--- Current Question ---" << endl;
    questions[index].displayQuestion();
    
    cout << "\n--- Enter New Details (press Enter to keep current) ---" << endl;
    cin.ignore();
    
    string input;
    
    cout << "\nNew Question Text: ";
    getline(cin, input);
    if (!input.empty()) {
        questions[index].setQuestionText(input);
    }
    
    cout << "New Option A: ";
    getline(cin, input);
    if (!input.empty()) {
        questions[index].setOptionA(input);
    }
    
    cout << "New Option B: ";
    getline(cin, input);
    if (!input.empty()) {
        questions[index].setOptionB(input);
    }
    
    cout << "New Option C: ";
    getline(cin, input);
    if (!input.empty()) {
        questions[index].setOptionC(input);
    }
    
    cout << "New Option D: ";
    getline(cin, input);
    if (!input.empty()) {
        questions[index].setOptionD(input);
    }
    
    cout << "New Correct Answer (A/B/C/D): ";
    getline(cin, input);
    if (!input.empty()) {
        char newAnswer = input[0];
        if (newAnswer >= 'a' && newAnswer <= 'd') {
            newAnswer = newAnswer - 32;
        }
        if (newAnswer >= 'A' && newAnswer <= 'D') {
            questions[index].setCorrectAnswer(newAnswer);
        }
    }
    
    cout << "New Marks: ";
    getline(cin, input);
    if (!input.empty()) {
        int newMarks = atoi(input.c_str());
        if (validatePositiveInt(newMarks)) {
            questions[index].setMark(newMarks);
        }
    }
    
    return true;
}

bool Exam::deleteQuestion(int questionNum) {
    if (questionNum < 1 || questionNum > (int)questions.size()) {
        return false;
    }
    
    questions.erase(questions.begin() + (questionNum - 1));
    
    for (size_t i = 0; i < questions.size(); i++) {
        questions[i].setQuestionId(i + 1);
    }
    
    return true;
}

bool Exam::isActive() const {
    return status == ACTIVE;
}

// Module-level functions using vector
void createExam(vector<ExamType> &exams) {
    clearScreen();
    displayHeader("CREATE NEW EXAM");
    
    int tempId;
    while (true) {
        cout << "Enter Exam ID: ";
        if (!(cin >> tempId)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        cin.ignore();
        
        if (!validatePositiveInt(tempId)) {
            cout << "Error: Exam ID must be positive!" << endl;
            continue;
        }
        
        if (searchExam(exams, tempId) != -1) {
            cout << "Error: Exam ID already exists! Try another ID." << endl;
            continue;
        }
        
        break;
    }
    
    string tempCourse;
    while (true) {
        cout << "Enter Course Name: ";
        getline(cin, tempCourse);
        
        if (tempCourse.empty()) {
            cout << "Error: Course name cannot be empty!" << endl;
            continue;
        }
        break;
    }
    
    int tempDuration;
    while (true) {
        cout << "Enter Duration (minutes): ";
        if (!(cin >> tempDuration)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        if (!validatePositiveInt(tempDuration)) {
            cout << "Error: Duration must be positive!" << endl;
            continue;
        }
        
        break;
    }
    
    ExamType newExam(tempId, tempCourse, tempDuration);
    exams.push_back(newExam);
    
    saveExamsToFile(exams);
    
    cout << "\nExam created successfully!" << endl;
    cout << "Data saved to file automatically." << endl;
    
    char addQuestions;
    cout << "\nDo you want to add questions now? (Y/N): ";
    cin >> addQuestions;
    cin.ignore();
    
    if (addQuestions == 'Y' || addQuestions == 'y') {
        int examIndex = searchExam(exams, tempId);
        addQuestionsToExam(exams, examIndex);
    } else {
        cout << "You can add questions later from the main menu." << endl;
        pauseSystem();
    }
}

void addQuestionsToExam(vector<ExamType> &exams, int examIndex) {
    clearScreen();
    displayHeader("ADD QUESTIONS TO EXAM");
    
    cout << "Exam: " << exams[examIndex].getCourseName() << endl;
    cout << "Current Questions: " << exams[examIndex].getTotalQuestions() << endl;
    displayLine();
    
    int numQuestions;
    while (true) {
        cout << "\nHow many questions do you want to add? ";
        if (!(cin >> numQuestions)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        if (numQuestions <= 0) {
            cout << "Error: Number must be positive!" << endl;
            continue;
        }
        
        break;
    }
    
    int addedCount = 0;
    
    for (int i = 0; i < numQuestions; i++) {
        clearScreen();
        displayHeader("ADD QUESTION");
        cout << "Exam: " << exams[examIndex].getCourseName() << endl;
        cout << "Adding question " << (i + 1) << " of " << numQuestions << endl;
        cout << "Current total: " << exams[examIndex].getTotalQuestions() << " questions" << endl;
        displayLine();
        
        cout << "\nType 'exit' in question text to stop adding questions." << endl;
        
        QuestionType newQuestion;
        newQuestion.inputQuestionData();
        
        if (newQuestion.getQuestionText() == "exit" || newQuestion.getQuestionText() == "EXIT") {
            cout << "\nStopping question addition..." << endl;
            break;
        }
        
        exams[examIndex].addQuestion(newQuestion);
        addedCount++;
        
        cout << "\nQuestion " << (i + 1) << " added successfully!" << endl;
        cout << "Total questions now: " << exams[examIndex].getTotalQuestions() << endl;
        
        if (i < numQuestions - 1) {
            cout << "\nPress Enter to add next question...";
            cin.ignore();
            cin.get();
        }
    }
    
    if (addedCount > 0) {
        saveExamsToFile(exams);
        cout << "\n" << addedCount << " question(s) added successfully!" << endl;
        cout << "Data saved to file automatically." << endl;
        cout << "Total questions in exam: " << exams[examIndex].getTotalQuestions() << endl;
    } else {
        cout << "\nNo questions were added." << endl;
    }
    
    pauseSystem();
}

void addQuestion(vector<ExamType> &exams) {
    clearScreen();
    displayHeader("ADD QUESTIONS TO EXAM");
    
    if (exams.empty()) {
        cout << "No exams available. Create an exam first." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    while (true) {
        cout << "Enter Exam ID: ";
        if (!(cin >> examId)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        break;
    }
    
    int examIndex = searchExam(exams, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    addQuestionsToExam(exams, examIndex);
}

void editQuestion(vector<ExamType> &exams) {
    clearScreen();
    displayHeader("EDIT QUESTION");
    
    if (exams.empty()) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    while (true) {
        cout << "Enter Exam ID: ";
        if (!(cin >> examId)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        break;
    }
    cin.ignore();
    
    int examIndex = searchExam(exams, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    if (exams[examIndex].getTotalQuestions() == 0) {
        cout << "This exam has no questions!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\nExam: " << exams[examIndex].getCourseName() << endl;
    cout << "Total Questions: " << exams[examIndex].getTotalQuestions() << endl;
    displayLine();
    
    int questionNum;
    while (true) {
        cout << "\nEnter Question Number to Edit (1-" << exams[examIndex].getTotalQuestions() << "): ";
        if (!(cin >> questionNum)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        if (questionNum >= 1 && questionNum <= exams[examIndex].getTotalQuestions()) {
            break;
        }
        
        cout << "Error: Question number must be between 1 and " << exams[examIndex].getTotalQuestions() << endl;
    }
    
    if (exams[examIndex].editQuestion(questionNum)) {
        saveExamsToFile(exams);
        cout << "\nQuestion updated successfully!" << endl;
        cout << "Data saved to file automatically." << endl;
    } else {
        cout << "\nError updating question!" << endl;
    }
    
    pauseSystem();
}

void deleteQuestion(vector<ExamType> &exams) {
    clearScreen();
    displayHeader("DELETE QUESTION");
    
    if (exams.empty()) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    while (true) {
        cout << "Enter Exam ID: ";
        if (!(cin >> examId)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        break;
    }
    cin.ignore();
    
    int examIndex = searchExam(exams, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    if (exams[examIndex].getTotalQuestions() == 0) {
        cout << "This exam has no questions!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\nExam: " << exams[examIndex].getCourseName() << endl;
    cout << "Total Questions: " << exams[examIndex].getTotalQuestions() << endl;
    displayLine();
    
    int questionNum;
    while (true) {
        cout << "\nEnter Question Number to Delete (1-" << exams[examIndex].getTotalQuestions() << "): ";
        if (!(cin >> questionNum)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        
        if (questionNum >= 1 && questionNum <= exams[examIndex].getTotalQuestions()) {
            break;
        }
        
        cout << "Error: Question number must be between 1 and " << exams[examIndex].getTotalQuestions() << endl;
    }
    cin.ignore();
    
    cout << "\nQuestion to Delete:" << endl;
    displayLine();
    cout << exams[examIndex].getQuestion(questionNum - 1).getQuestionText() << endl;
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
    
    if (exams[examIndex].deleteQuestion(questionNum)) {
        saveExamsToFile(exams);
        cout << "\nQuestion deleted successfully!" << endl;
        cout << "Data saved to file automatically." << endl;
        cout << "Remaining questions: " << exams[examIndex].getTotalQuestions() << endl;
    } else {
        cout << "\nError deleting question!" << endl;
    }
    
    pauseSystem();
}

void updateExam(vector<ExamType> &exams) {
    clearScreen();
    displayHeader("UPDATE EXAM");
    
    if (exams.empty()) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    while (true) {
        cout << "Enter Exam ID to Update: ";
        if (!(cin >> examId)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        break;
    }
    cin.ignore();
    
    int examIndex = searchExam(exams, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    clearScreen();
    displayHeader("CURRENT EXAM DETAILS");
    exams[examIndex].displayExamDetails();
    displayLine();
    
    cout << "\nEnter New Details (press Enter to keep current value):" << endl;
    displayLine();
    
    string input;
    
    cout << "\nNew Course Name: ";
    getline(cin, input);
    if (!input.empty()) {
        exams[examIndex].setCourseName(input);
    }
    
    cout << "New Duration (minutes): ";
    getline(cin, input);
    if (!input.empty()) {
        int newDuration = atoi(input.c_str());
        if (validatePositiveInt(newDuration)) {
            exams[examIndex].setDurationMinutes(newDuration);
        } else {
            cout << "Invalid duration! Keeping current value." << endl;
        }
    }
    
    cout << "New Status (0=Active, 1=Inactive, 2=Completed): ";
    getline(cin, input);
    if (!input.empty()) {
        int statusChoice = atoi(input.c_str());
        if (statusChoice >= 0 && statusChoice <= 2) {
            exams[examIndex].setStatus(static_cast<ExamStatusType>(statusChoice));
        } else {
            cout << "Invalid status! Keeping current value." << endl;
        }
    }
    
    cout << "\nExam updated successfully!" << endl;
    saveExamsToFile(exams);
    cout << "Data saved to file automatically." << endl;
    pauseSystem();
}

void deleteExam(vector<ExamType> &exams) {
    clearScreen();
    displayHeader("DELETE EXAM");
    
    if (exams.empty()) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    while (true) {
        cout << "Enter Exam ID to Delete: ";
        if (!(cin >> examId)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        break;
    }
    cin.ignore();
    
    int examIndex = searchExam(exams, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    cout << "\nExam to Delete:" << endl;
    displayLine();
    exams[examIndex].displayExamDetails();
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
    
    exams.erase(exams.begin() + examIndex);
    
    saveExamsToFile(exams);
    
    cout << "\nExam deleted successfully!" << endl;
    cout << "Data saved to file automatically." << endl;
    cout << "Remaining exams: " << exams.size() << endl;
    pauseSystem();
}

void displayExams(const vector<ExamType> &exams) {
    clearScreen();
    displayHeader("ALL EXAMS");
    
    if (exams.empty()) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    for (size_t i = 0; i < exams.size(); i++) {
        cout << "\n--- Exam " << (i + 1) << " ---" << endl;
        exams[i].displayExamDetails();
        displayLine();
    }
    
    cout << "\nTotal Exams: " << exams.size() << endl;
    pauseSystem();
}

int searchExam(const vector<ExamType> &exams, int examId) {
    for (size_t i = 0; i < exams.size(); i++) {
        if (exams[i].getExamId() == examId) {
            return i;
        }
    }
    return -1;
}

void takeExam(const vector<ExamType> &exams, string studentId, vector<Result> &results) {
    clearScreen();
    displayHeader("TAKE EXAM");
    
    if (exams.empty()) {
        cout << "No exams available." << endl;
        pauseSystem();
        return;
    }
    
    cout << "Available Exams:" << endl;
    displayLine();
    bool hasActiveExams = false;
    for (size_t i = 0; i < exams.size(); i++) {
        if (exams[i].isActive() && exams[i].getTotalQuestions() > 0) {
            cout << "Exam ID: " << exams[i].getExamId() 
                 << " | Course: " << exams[i].getCourseName() 
                 << " | Questions: " << exams[i].getTotalQuestions() << endl;
            hasActiveExams = true;
        }
    }
    displayLine();
    
    if (!hasActiveExams) {
        cout << "No active exams with questions available." << endl;
        pauseSystem();
        return;
    }
    
    int examId;
    while (true) {
        cout << "\nEnter Exam ID to take: ";
        if (!(cin >> examId)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Please enter a valid number!" << endl;
            continue;
        }
        break;
    }
    
    int examIndex = searchExam(exams, examId);
    
    if (examIndex == -1) {
        cout << "Exam not found!" << endl;
        pauseSystem();
        return;
    }
    
    if (!exams[examIndex].isActive()) {
        cout << "This exam is not active!" << endl;
        pauseSystem();
        return;
    }
    
    if (exams[examIndex].getTotalQuestions() == 0) {
        cout << "This exam has no questions!" << endl;
        pauseSystem();
        return;
    }
    
    if (searchResult(results, studentId, examId) != -1) {
        cout << "You have already taken this exam!" << endl;
        cout << "View your results from the main menu." << endl;
        pauseSystem();
        return;
    }
    
    clearScreen();
    displayHeader(exams[examIndex].getCourseName());
    cout << "Duration: " << exams[examIndex].getDurationMinutes() << " minutes" << endl;
    cout << "Total Questions: " << exams[examIndex].getTotalQuestions() << endl;
    cout << "\nPress Enter to start...";
    cin.ignore();
    cin.get();
    
    int score = 0;
    int totalMarks = 0;
    
    for (int i = 0; i < exams[examIndex].getTotalQuestions(); i++) {
        clearScreen();
        QuestionType currentQuestion = exams[examIndex].getQuestion(i);
        
        cout << "Question " << (i + 1) << " of " << exams[examIndex].getTotalQuestions() << endl;
        displayLine();
        currentQuestion.displayQuestion();
        displayLine();
        
        char answer;
        while (true) {
            cout << "Your Answer (A/B/C/D): ";
            cin >> answer;
            
            if (answer >= 'a' && answer <= 'd') {
                answer = answer - 32;
            }
            
            if (answer >= 'A' && answer <= 'D') {
                break;
            }
            
            cout << "Error: Please enter A, B, C, or D only!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        totalMarks += currentQuestion.getMark();
        
        if (currentQuestion.checkAnswer(answer)) {
            score += currentQuestion.getMark();
        }
    }
    
    ResultType newResult(studentId, examId, score, totalMarks);
    results.push_back(newResult);
    
    saveResultsToFile(results);
    
    clearScreen();
    displayHeader("EXAM COMPLETED");
    newResult.displayResult();
    cout << "\nResult saved to file automatically." << endl;
    pauseSystem();
}
