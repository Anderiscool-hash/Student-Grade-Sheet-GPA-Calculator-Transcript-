#ifndef GradeSheet.h
#define GradeSheet.h

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
    // Constructor
       Course(string name, int credits, string grade);
    // Member functions
       string getCourseName() const;
       int getCreditHours() const;
       string getLetterGrade() const;
       double getGradePoint() const;
       double getTotalGradePoints() const;
};
class  Student {
    private:
        // Member variables
        string studentName;
        vector<Course> courses;
    public:
    // Constructor
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

