#include <iostream>
using namespace std;

//Write a student class that has two private member variables: name and grade (e.g., 6, 11).
//Write the functions to access those private member variables. Write the default constructor.
//Write the function graduate that is not part of the class which increases the grade of a student by one. This function should be called by passing a student object by reference.
//Write a main method that creates an instance of the student class, prints out the grade, calls graduate on it, and prints out the new grade.
//Sample output:
//
//Sally is in grade 5.
//Sally is in grade 6.

class Student {
private:
    string name;
    int grade;
    
public:
    Student() {
        name = "";
        grade = 0;
    };
    
    string getName() {
        return name;
    }
    
    void setName(string newName) {
        name = newName;
    }
    
    int getGrade() {
        return grade;
    }
    
    void setGrade(int newGrade) {
        grade = newGrade;
    }
};

void graduate(Student & someStudent) {
    someStudent.setGrade(someStudent.getGrade() + 1);
}

int main() {
    Student student;
    
    student.setGrade(5);
    student.setName("Sally");
    
    cout << student.getName() << " is in grade " << student.getGrade() << "." << endl;
    
    graduate(student);
    
    cout << student.getName() << " is in grade " << student.getGrade() << "." << endl;
}