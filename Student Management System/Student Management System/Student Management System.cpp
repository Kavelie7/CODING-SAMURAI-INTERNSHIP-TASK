// StudentSystem.cpp
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Struct to hold student data
struct Student {
    int rollNo;
    string name;
    float marks;
};

// Global array to store students
Student students[100];
int studentCount = 0;

// Function to add a student
void addStudent() {
    if (studentCount >= 100) {
        cout << "Student limit reached!" << endl;
        return;
    }

    cout << "Enter roll number: ";
    cin >> students[studentCount].rollNo;
    cout << "Enter name: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, students[studentCount].name);
    cout << "Enter marks: ";
    cin >> students[studentCount].marks;

    cout << "Student added successfully." << endl;
    studentCount++;
}

// Function to display all students
void viewStudents() {
    if (studentCount == 0) {
        cout << "No students to display." << endl;
        return;
    }

    cout << "\nList of Students:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Roll No: " << students[i].rollNo << ", ";
        cout << "Name: " << students[i].name << ", ";
        cout << "Marks: " << students[i].marks << endl;
    }
}

// Function to search for a student
void searchStudent() {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            cout << "Student Found:\n";
            cout << "Roll No: " << students[i].rollNo << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }

    cout << "Student with roll number " << roll << " not found." << endl;
}

// Function to delete a student
void deleteStudent() {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Management System =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            cout << "Exiting Student Management System." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
