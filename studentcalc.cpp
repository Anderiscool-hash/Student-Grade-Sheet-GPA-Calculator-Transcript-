#include <iostream>
#include <iomanip>
#include "studentcalc.h"

using namespace std;

// First Course = Class Name; Second Course = Constructor;

// ======== Course ========

Course::Course() {
	coursename = "Unknown";
	creditHours = 0;
	letterGrade = "F";
}

Course::Course(string name, int credits, string grade) {
	coursename = name;
	creditHours = credits;
	letterGrade = grade;
}

string Course::getCourseName() const {
	return coursename;
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