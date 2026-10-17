/* CSCI 272-2 Assignment 3: Student Grade Sheet (GPA Calculator / Transcript)
   Group members contributed: Samiul Islam, Ander Ayala.
   Date: 10/16/2026
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cctype>

#include "studentcalc.h"
using namespace std;


// checks the grade if one of the allowed letter grades
bool isValidGrade(string grade) {
    if (grade == "A" || grade == "A-" || grade == "B+" || grade == "B" || grade == "B-" ||
           grade == "C+" || grade == "C" || grade == "C-" || grade == "D" || grade == "F")
           return true;
    else
           return false;
}

// execution
int main() {
    string name;
    int numCourses;

    cout << "=== PLEASE ENTER STUDENT NAME ===" << endl;
    getline(cin, name);

    Student student(name);

    cout << "Enter number of courses (1-10): ";
    cin >> numCourses;

    // re-prompt until we get a number from 1 to 10
    while (cin.fail() || numCourses < 1 || numCourses > 10) {
        cin.clear();                // reset the error flag
        cin.ignore(1000, '\n');     // throw away the bad input
        cout << "Invalid input. Please enter a whole number between 1 and 10: ";
        cin >> numCourses;
    }
    cin.ignore(1000, '\n'); // remove the leftover. Enter before a getline

    for (int i = 1; i <= numCourses; i++) {
        string courseName;
        int credits;
        string grade;

        // course name can have spaces, so we use getline
        cout << "Enter course name for course " << i << ": ";
        getline(cin, courseName);

        // credits must be a whole number >= 0
        cout << "Enter credit hourse: ";
        cin >> credits;
        while (cin.fail() || credits < 0) {
            cin.clear();                // reset the error flag
            cin.ignore(1000, '\n');     // throw away the bad input
            cout << "Invalid input. Please enter a whole number greater than or equal to 0: ";
            cin >> credits;
        }

        cout << "letter grade (A, A-, B+, B, B-, C+, C, C-, D, F): ";
        cin >> grade;
        while (isValidGrade(grade) == false) {
            cin.ignore(1000, '\n');
            cout << "Invalid grade. Try again: ";
            cin >> grade;
        }
        cin.ignore(1000, '\n'); // clear the line before next getline

        Course course(courseName, credits, grade);
        student.addCourse(course);
    }
    
    student.printTranscript();

    return 0;
}




/* Ander Ayala reflection:
(a) Something that was tricky was understanding the classes and how to implement them correctly. I had to make sure that the member functions were properly defined and that the data members were being accessed correctly.
(b) Something i learnt was how to create a class because i couldnt figure out how to do it at first but after some research and practice i was able to create a class and implement it correctly.
*/