@echo off
REM ============================================================
REM COMPILATION SCRIPT FOR WINDOWS
REM ============================================================
REM This script compiles the Online Exam Management System
REM using g++ compiler (MinGW)
REM ============================================================

echo ============================================================
echo COMPILING ONLINE EXAM MANAGEMENT SYSTEM
echo ============================================================
echo.

REM Compile all source files
g++ -std=c++11 main.cpp student.cpp exam.cpp result.cpp filemanager.cpp utility.cpp -o exam_system.exe

REM Check if compilation was successful
if %ERRORLEVEL% EQU 0 (
    echo.
    echo ============================================================
    echo COMPILATION SUCCESSFUL!
    echo ============================================================
    echo.
    echo Executable created: exam_system.exe
    echo.
    echo Starting the program...
    echo ============================================================
    echo.
    exam_system.exe
) else (
    echo.
    echo ============================================================
    echo COMPILATION FAILED!
    echo ============================================================
    echo Please check for errors above.
    echo.
)

pause
