#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
using namespace std;

// Template function: Swap two values of any type
template <typename T>
void swapData(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function: Display value with label
template <typename T>
void displayValue(const string &label, const T &value) {
    cout << label << ": " << value << endl;
}

// Template function: Search for value in array
template <typename T>
int searchRecord(T arr[], int size, T key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Utility function declarations
void clearScreen();
void pauseSystem();
void displayHeader(const string &title);
void displayLine();
bool validatePositiveInt(int value);
bool validateChoice(int choice, int min, int max);

#endif
