#!/bin/bash
# ============================================================
# COMPILATION SCRIPT FOR LINUX/MAC
# ============================================================
# This script compiles the Online Exam Management System
# using g++ compiler
# ============================================================

echo "============================================================"
echo "COMPILING ONLINE EXAM MANAGEMENT SYSTEM"
echo "============================================================"
echo ""

# Compile all source files
g++ -std=c++11 main.cpp student.cpp exam.cpp result.cpp filemanager.cpp utility.cpp -o exam_system

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo ""
    echo "============================================================"
    echo "COMPILATION SUCCESSFUL!"
    echo "============================================================"
    echo ""
    echo "Executable created: exam_system"
    echo ""
    echo "Starting the program..."
    echo "============================================================"
    echo ""
    ./exam_system
else
    echo ""
    echo "============================================================"
    echo "COMPILATION FAILED!"
    echo "============================================================"
    echo "Please check for errors above."
    echo ""
fi
