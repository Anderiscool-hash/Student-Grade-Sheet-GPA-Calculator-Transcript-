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
        cout << "Enter credit hours: ";
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




/* 
Ander Ayala's reflection:
(a) Something that was tricky was understanding the classes and how to implement them correctly. I had to make sure that the member functions were properly defined and that the data members were being accessed correctly.
(b) Something I learnt was how to create a class because I couldnt figure out how to do it at first but after some research and practice I was able to create a class and implement it correctly.

Samiul Islam's reflection:
The specific things I struggled with were choosing the column widths for the transcript table and setting up the constructors. I fixed them by applying what I learned in class about streams and constructors: the course name 
column is 28 wide because names like “CSCI 272” need room, and the numbers use right so the decimals line up. The variables and functions are declared in studentcalc.h, and I defined them in studentcalc.cpp using Course:: and Student::. 
In main.cpp, a for loop asks for each course’s name, credits and grade once for every course the user entered, and while loops keep re-asking until the input is valid. One thing I understand now that I didn’t before is that a function declared 
in the .h file doesn’t work until it is defined in the .cpp file with the class name in front, like Student::calculateGPA().
*/