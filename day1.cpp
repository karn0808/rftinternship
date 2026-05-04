#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float marks;

public:
    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nName: " << name;
        cout << "\nRoll: " << roll;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << calculateGrade() << endl;
    }

    char calculateGrade() {
        if (marks >= 80) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 40) return 'C';
        else return 'F';
    }

    float getMarks() {
        return marks;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[n];

    // Input
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        s[i].input();
    }

    // Display
    cout << "\n--- Student Details ---\n";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    // Average
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i].getMarks();
    }
    cout << "\nAverage Marks: " << sum / n << endl;

    // Topper
    int topIndex = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].getMarks() > s[topIndex].getMarks()) {
            topIndex = i;
        }
    }

    cout << "\n--- Topper ---";
    s[topIndex].display();

    return 0;
}
