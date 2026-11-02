#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;

    // Parameterized constructor
    Student(int id, string name, float marks) {
        this->id = id;
        this->name = name;
        this->marks = marks;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    // Add student
    void addStudent() {
        int id;
        string name;
        float marks;

        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Invalid marks! Enter marks from 0 to 100.\n";
            return;
        }

        students.push_back(Student(id, name, marks));
        cout << "Student added successfully!\n";
    }

    // Display all students
    void displayStudents() {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\n";
        cout << left << setw(10) << "ID"
             << setw(25) << "Name"
             << right << setw(10) << "Marks"
             << setw(12) << "Result" << endl;

        cout << string(57, '-') << endl;

        for (Student s : students) {
            cout << left << setw(10) << s.id
                 << setw(25) << s.name
                 << right << setw(10) << fixed
                 << setprecision(2) << s.marks
                 << setw(12);

            if (s.marks >= 40)
                cout << "PASS";
            else
                cout << "FAIL";

            cout << endl;
        }
    }

    // Search student by ID
    void searchStudent() {
        int searchId;

        cout << "Enter Student ID to search: ";
        cin >> searchId;

        for (Student s : students) {
            if (s.id == searchId) {
                cout << "\nStudent Found!\n";
                cout << "ID: " << s.id << endl;
                cout << "Name: " << s.name << endl;
                cout << "Marks: " << fixed
                     << setprecision(2) << s.marks << endl;

                checkResult(s.marks);
                return;
            }
        }

        cout << "Student not found!\n";
    }

    // Check student result
    void checkResult(float marks) {
        if (marks >= 40)
            cout << "Result: PASS\n";
        else
            cout << "Result: FAIL\n";
    }

    // Student management menu
    void studentManagement() {
        int choice;

        do {
            cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
            cout << "1. Add Student\n";
            cout << "2. Display Students\n";
            cout << "3. Search Student\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent();
                    break;

                case 2:
                    displayStudents();
                    break;

                case 3:
                    searchStudent();
                    break;

                case 4:
                    cout << "Thank you!\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        } while (choice != 4);
    }
};

int main() {
    StudentManager manager;
    manager.studentManagement();

    return 0;
}