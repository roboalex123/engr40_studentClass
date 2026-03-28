#ifndef student_h
#define student_h

#include <string>

class Student {
private:
  std::string name;  // Student name
  int id;            // A numeric identifier for the student
  int semester;      // A numeric identifier representing the student's current
                     // semester
  std::string major; // A string representing the student's major
  int points; // An integer value indicating the number of points the student
              // has recieved so far
public:
  // Constructors
  Student();
  Student(std::string studentName, int studentId, int studentSemester,
          std::string studentMajor, int studentPoints);

  // Getters
  std::string getName() const { return name; }
  int getID() const { return id; }
  int getSemester() const { return semester; }
  std::string getMajor() const { return major; }
  int getPoints() const { return points; }

  // Setters
  void setName(std::string studentName) { name = studentName; }
  void setID(int studentId) { id = studentId; }
  void setSemester(int studentSemester) { semester = studentSemester; }
  void setMajor(std::string studentMajor) { major = studentMajor; }
  void setPoints(int studentPoints) { points = studentPoints; }

  // Methods
  void printAllInfo() const;
  void printSimplified() const;

  void gradeAssignment(int assignmentPoints);
  char letterGrade() const;
};

#endif // student
