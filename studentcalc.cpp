#include <iostream>
#include <iomanip>
#include "studentcalc.h"

using namespace std;

// First Course = Class Name; Second Course = Constructor;

// ======== Course ========

Course::Course() {
	courseName = "Unknown";
	creditHours = 0;
	letterGrade = "F";
}

Course::Course(string name, int credits, string grade) {
	courseName = name;
	creditHours = credits;
	letterGrade = grade;
}

string Course::getCourseName() const {
	return courseName;
}

int Course::getCreditHours() const {
	return creditHours;
}

string Course::getLetterGrade() const {
	return letterGrade;
}

// letter grade to grade point conversion
double Course::getGradePoint() const {
	if (letterGrade == "A") return 4.0;
	else if (letterGrade == "A-") return 3.7;
	else if (letterGrade == "B+") return 3.3;
	else if (letterGrade == "B") return 3.0;
	else if (letterGrade == "B-") return 2.7;
	else if (letterGrade == "C+") return 2.3;
	else if (letterGrade == "C") return 2.0;
	else if (letterGrade == "C-") return 1.7;
	else if (letterGrade == "D") return 1.0;
	else return 0.0; // F
}

// total grade points = credit hours * grade point
double Course::getTotalGradePoints() const {
	return creditHours * getGradePoint();
}

// ======== Student ========

Student::Student(string name) {
	studentName = name;
}

void Student::addCourse(const Course& course) {
	courses.push_back(course);
}

int Student::getTotalCredits() const {
	int totalCredits = 0;
	for (size_t i = 0; i < courses.size(); i++) {
		totalCredits += courses[i].getCreditHours();
	}
	return totalCredits;
}

double Student::getTotalPoints() const {
	double totalPoints = 0.0;
	for (size_t i = 0; i < courses.size(); i++) {
		totalPoints += courses[i].getTotalGradePoints();
	}
	return totalPoints;
}

// GPA = total grade points / total credit hours
double Student::calculateGPA() const {
	if (getTotalCredits() == 0) {
		return 0.0; // avoid division by zero
	}
	return getTotalPoints() / getTotalCredits();
}

string Student::getStanding() const {
	double gpa = calculateGPA();
	if (gpa >= 3.70) return "Dean's List";
	else if (gpa >= 2.0) return "Good Standing";
	else return "Probation";
}
void Student::printTranscript() const {
	// title
	cout << "\n";
	cout << setfill('=') << setw(19) << "" << "Student Grade Report" << setw(19) << "" << endl;
	cout << setfill(' ');	// restore normal spacing
	cout << "Student: " << studentName << endl << endl;


	// column headers
	cout << left << setw(28) << "Course" << right << setw(8) << "Credits" << setw(10) << "GradePts" << setw(10) << "TotalPts" << endl;

	cout << setfill('-') << setw(56) << "" << endl;
	cout << setfill(' ');

	// fixed makes precision = number of decimal places
	cout << fixed << setprecision(2);

	// one row for each course
	for (size_t i = 0; i < courses.size(); i++) {
	cout << left << setw(28) << courses[i].getCourseName()
		 << right << setw(8) << courses[i].getCreditHours()
		 << setw(10) << courses[i].getGradePoint()
		 << setw(10) << courses[i].getTotalGradePoints() << endl;
	}
	cout << setfill('-') << setw(56) << "" << endl;
	cout << setfill(' ');

	// totals
	cout << left << setw(28) << "Total Credits:" << right << setw(8) << getTotalCredits() << endl;
	cout << left << setw(28) << "Total Points:" << right << setw(10) << getTotalPoints() << endl;
	cout << left << setw(28) << "Semester GPA:" << right << setw(10) << calculateGPA() << endl;
	cout << left << setw(28) << "Standing:" << right << setw(15) << getStanding() << endl;
 
	cout << setfill('=') << setw(60) << "" << endl;
}