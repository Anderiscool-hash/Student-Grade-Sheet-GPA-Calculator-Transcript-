#include <iostream>
#include <vector>
#include <iomanip>

#include "studentcalc.h"
using namespace std;



int main() {
    string name;
    int numCourses;

    cout << "=== PLEASE ENTER STUDENT NAME ===" << endl;
    getline(cin, name);

    Student student(name);

    

    return 0;
}




// Ander Ayala
//reflection:
// Something that was tricky was understanding the classes and how to implement them correctly. I had to make sure that the member functions were properly defined and that the data members were being accessed correctly.
// Something i learnt was how to create a class because i couldnt figure out how to do it at first but after some research and practice i was able to create a class and implement it correctly.
