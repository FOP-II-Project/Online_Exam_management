#include "utility.h"
#include <cstdlib>

// Clear console screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Pause and wait for user input
void pauseSystem() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

// Display formatted header
void displayHeader(const string &title) {
    displayLine();
    cout << "          " << title << endl;
    displayLine();
}

// Display decorative line
void displayLine() {
    for (int i = 0; i < 60; i++) {
        cout << "=";
    }
    cout << endl;
}

// Validate integer is positive
bool validatePositiveInt(int value) {
    return value > 0;
}

// Validate menu choice is in range
bool validateChoice(int choice, int min, int max) {
    return (choice >= min && choice <= max);
}
