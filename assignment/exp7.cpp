#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int roll;
    string name;

public:
    void getdata() {
        cout << "\n-----------------------------------------";
        cout << "\nEnter Roll No.   : ";
        cin >> roll;
        cout << "Enter Student Name: ";
        cin.ignore(); // Clears input buffer before reading string
        getline(cin, name);
    }

    void putdata() {
        cout << "\n-----------------------------------------";
        cout << "\n********** Student Marklist **********";
        cout << "\n-----------------------------------------";
        cout << "\nRoll No.    : " << roll;
        cout << "\nStudent Name: " << name << endl;
    }
};

// Class StudentExam derived from Class Student (Single Inheritance Step)
class StudentExam : public Student {
public:
    int sub1, sub2, sub3, sub4, sub5, sub6;
    float per;

    void accept_data() {
        getdata();
        cout << "Enter Marks for Subject 1: "; cin >> sub1;
        cout << "Enter Marks for Subject 2: "; cin >> sub2;
        cout << "Enter Marks for Subject 3: "; cin >> sub3;
        cout << "Enter Marks for Subject 4: "; cin >> sub4;
        cout << "Enter Marks for Subject 5: "; cin >> sub5;
        cout << "Enter Marks for Subject 6: "; cin >> sub6;
    }

    void display_data() {
        putdata();
        cout << "Marks of Subject 1: " << sub1 << endl;
        cout << "Marks of Subject 2: " << sub2 << endl;
        cout << "Marks of Subject 3: " << sub3 << endl;
        cout << "Marks of Subject 4: " << sub4 << endl;
        cout << "Marks of Subject 5: " << sub5 << endl;
        cout << "Marks of Subject 6: " << sub6 << endl;
    }
};

// Class StudentResult derived from Class StudentExam (Multilevel Inheritance)
class StudentResult : public StudentExam {
public:
    void calculate() {
        per = (sub1 + sub2 + sub3 + sub4 + sub5 + sub6) / 6.0f;
        cout << "Total Percentage  : " << per << "%";
        cout << "\n----------------------------------------- \n";
    }
};

int main() {
    int cnt;
    cout << "\nEnter No. of Students You Want? : ";
    cin >> cnt;

    // Notice: To handle multiple students correctly without overwriting, 
    // an array or a loop processing dynamic objects is ideal.
    for (int i = 0; i < cnt; i++) {
        StudentResult str; // Created inside the loop for separate student inputs
        cout << "\n--- Entering Details for Student " << (i + 1) << " ---" << endl;
        str.accept_data();
        str.display_data();
        str.calculate();
    }

    return 0;
}
