#include "student.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// menu globals
vector<string> menuOptions = {
    "Add a student",
    "Add multiple students (CSV)",
    "Drop a student by ID",
    "Print a student by ID",
    "Print all students",
    "Grade an assignment",
    "Grade multiple assignments (CSV)",
    "Exit",
};

int getInteger();

void printMenu();

Student addStudent();
void addMultipleStudents(vector<Student> &roster);

void gradeAssignment(vector<Student> &roster, int id, int points);
void gradeMultipleAssignments(vector<Student> &roster);

int main() {
  vector<Student> roster;

  while (true) {
    printMenu();

    cout << "Select an option: ";
    int choice = getInteger() - 1;

    if (choice == 0) {
      Student newStudent = addStudent();
      roster.push_back(newStudent);
    } else if (choice == 2) {
      addMultipleStudents(roster);
    } else if (choice == 3) {
      if (roster.size() == 0) {
        cout << "No students in roster" << endl;
        continue;
      }

      cout << "Enter student ID: ";
      int id = getInteger();

      for (int i = 0; i < roster.size(); i++) {
        if (roster.at(i).getID() == id) {
          roster.erase(roster.begin() + i);
          break;
        }
      }
    } else if (choice == 4) {
      if (roster.size() == 0) {
        cout << "No students in roster" << endl;
        continue;
      }

      cout << "Enter student ID: ";
      int id = getInteger();

      for (int i = 0; i < roster.size(); i++) {
        if (roster.at(i).getID() == id) {
          roster.at(i).printAllInfo();
          break;
        }
      }
    } else if (choice == 5) {
      if (roster.size() == 0) {
        cout << "No students in roster" << endl;
        continue;
      }

      for (int i = 0; i < roster.size(); i++) {
        roster.at(i).printSimplified();
      }
    } else if (choice == 6) {
      if (roster.size() == 0) {
        cout << "No students in roster" << endl;
        continue;
      }

      cout << "Enter student ID: ";
      int id = getInteger();

      cout << "Enter assignment points: ";
      int points = getInteger();

      gradeAssignment(roster, id, points);
    } else if (choice == 7) {
      if (roster.size() == 0) {
        cout << "No students in roster" << endl;
        continue;
      }

      gradeMultipleAssignments(roster);
    } else if (choice == 8) {
      break;
    } else {
      cout << "Invalid choice" << endl;
    }
  }

  return 0;
}

int getInteger() {
  int num;
  cin >> num;

  while (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please enter an integer: ";
    cin >> num;
  }

  return num;
}

void printMenu() {

  for (int i = 0; i < menuOptions.size(); i++) {
    cout << i + 1 << ". " << menuOptions.at(i) << endl;
  }

  cout << endl;
}

Student addStudent() {
  cout << "Enter student name: ";
  string name;
  getline(cin, name);

  cout << "Enter student ID: ";
  cin.ignore(); // clear newline from buffer (for getline)
  int id = getInteger();

  cout << "Enter student semester: ";
  int semester = getInteger();

  cout << "Enter student major: ";
  string major;
  getline(cin, major);

  cout << "Enter student points: ";
  cin.ignore(); // clear newline from buffer (for getline)
  int points = getInteger();

  return Student(name, id, semester, major, points);
}

void addMultipleStudents(vector<Student> &roster) {
  int beforeNumStudents = roster.size();

  cout << "Enter a file name that contains student information: ";
  string fileName;
  getline(cin, fileName);

  fstream file(fileName);
  string line;
  while (getline(file, line)) {
    // column order: id, first name, last name, semester, major
    stringstream ss(line);
    int id;
    ss >> id;
    if (ss.fail()) {
      cout << "Invalid file format" << endl;
      break;
    }

    string firstName;
    ss >> firstName;
    if (ss.fail()) {
      cout << "Invalid file format" << endl;
      break;
    }

    string lastName;
    ss >> lastName;
    if (ss.fail()) {
      cout << "Invalid file format" << endl;
      break;
    }

    int semester;
    ss >> semester;
    if (ss.fail()) {
      cout << "Invalid file format" << endl;
      break;
    }

    string major;
    getline(ss, major); // no delimiter, last column
    if (ss.fail()) {
      cout << "Invalid file format" << endl;
      break;
    }

    roster.push_back(
        Student(firstName + " " + lastName, id, semester, major, 0));
  }

  cout << "Added " << roster.size() - beforeNumStudents << " students" << endl;
  if (roster.size() == beforeNumStudents) {
    cout << "No students added, check file format" << endl;
  }
}

void gradeAssignment(vector<Student> &roster, int id, int points) {
  for (int i = 0; i < roster.size(); i++) {
    if (roster.at(i).getID() == id) {
      roster.at(i).gradeAssignment(points);
      break;
    }
  }
}

void gradeMultipleAssignments(vector<Student> &roster) {
  int gradesAdded = 0;

  cout << "Enter a file name that contains assignment information: ";
  string fileName;
  getline(cin, fileName);

  fstream file(fileName);
  string line;
  while (getline(file, line)) {
    // column order: id, points
    stringstream ss(line);
    int id;
    ss >> id;
    if (ss.fail()) {
      cout << "Invalid file format" << endl;
      break;
    }

    int points;
    ss >> points;
    if (ss.fail()) {
      cout << "Invalid file format" << endl;
      break;
    }

    gradeAssignment(roster, id, points);
    gradesAdded++;
  }

  cout << "Added " << gradesAdded << " assignments" << endl;
  if (gradesAdded == 0) {
    cout << "No assignments added, check file format" << endl;
  }
}
