#include "student.h"
#include <iostream>
using namespace std;

// Constructors
Student::Student() {
  name = "John Doe";
  id = 1111;
}

Student::Student(string studentName, int studentID, int studentSemester,
                 string studentMajor, int studentPoints) {
  name = studentName;
  id = studentID;
  semester = studentSemester;
  major = studentMajor;
  points = studentPoints;
}

// Methods
void Student::printAllInfo() const {
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
  cout << "Semester: " << semester << endl;
  cout << "Major: " << major << endl;
  cout << "Points: " << points << endl;
}

void Student::printSimplified() const {
  cout << "Name: " << name << endl;
  cout << "ID: " << id << endl;
}

void Student::gradeAssignment(int assignmentPoints) {
  points += assignmentPoints;
}

char Student::letterGrade() const {
  if (points >= 90) {
    return 'A';
  } else if (points >= 80) {
    return 'B';
  } else if (points >= 70) {
    return 'C';
  } else if (points >= 60) {
    return 'D';
  } else {
    return 'F';
  }
}
