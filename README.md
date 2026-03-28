# Student Class and Main Program Assignment

## Overview
For this assignment, create a `Student` class and a main program to test that class.

---

## Student Class Requirements

Write a **header file** and an **implementation file** for a class named `Student` with the following properties:

- **Name**: a string representing the student's name
- **ID**: a numeric identifier for the student
- **Semester**: a numeric value representing the student's current semester
- **Major**: a string representing the student's major
- **Points**: an integer value indicating the amount of points the student has received so far

### Constructors
Implement the following constructors:

- A **default constructor** that sets:
  - `Name` to `"John Doe"`
  - `ID` to `1111`

- An **overloaded constructor** that takes input for **each property** and sets them accordingly

### Required Methods
Create methods in the `Student` class to do the following:

- **printAllInfo**  
  Print all details of the student

- **printSimplified**  
  Print only the student's name and ID

- **gradeAssignment**  
  Takes in a value and adds it to the grade

- **letterGrade**  
  Returns a `char` representation of the student's grade out of 1000 points using the following scale:
  - `A` for 90 and above
  - `B` for 80 and above
  - `C` for 70 and above
  - `D` for 60 and above
  - `F` for below 60

---

## Main Program Tester

Write a `main` function that does the following:

- Create a vector called `roster` of `Student` objects
  - It should start empty

- Create a menu with the following options:

  1. **Add a student**
     - This must accept **all necessary info** about the student

  2. **Add multiple students from a CSV file**
     - Column order:
       - `ID`
       - `Last name`
       - `First name`
       - `Semester`
       - `Major`

  3. **Drop a student based on ID number**

  4. **Print all of one student's info from the vector by asking for the ID to print**
     - Show the grade as **points out of 1000**

  5. **Print the Name, ID, and letter grade of every student in the vector**

  6. **Add grades to one student based on ID**

  7. **Add grades to all students with corresponding IDs based on data from a CSV file**
     - Column order:
       - `ID`
       - `points to add`

  8. **Quit program**

- Repeat the menu until the user chooses to quit
