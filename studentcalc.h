#ifndef STUDENTCALC_H
#define STUDENTCALC_H

#include <string>
#include <vector>
using namespace std;

class Course {
    private:
        // Member variables
        string courseName;
        int creditHours;
        string letterGrade;

    public:
    // default onstructor
    Course();

    // Parametrized constructor
    Course(string name, int credits, string grade);

    // Member functions (getters; const = they do not modify the object)
       string getCourseName() const;
       int getCreditHours() const;
       string getLetterGrade() const;
       double getGradePoint() const;
       double getTotalGradePoints() const;
};
class  Student {
    private:
        // data members
        string studentName;
        vector<Course> courses; // composition: a student has a vector of courses

    public:
        // Parametrized onstructor
        Student(string name);

        // Member functions
        void addCourse(const Course& course);
        
        int getTotalcredits() const;
        double getTotalPoints() const;
        double calculateGPA() const;
    
        string getStanding() const;
        void printTranscript() const;
};
#endif

