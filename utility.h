#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
using namespace std;

// Utility function declarations
void clearScreen();
void pauseSystem();
void displayHeader(const string &title);
void displayLine();
bool validatePositiveInt(int value);
bool validateChoice(int choice, int min, int max);

#endif
