#include<iostream>
#include"student.h"
#include"isort.h"
using namespace std;

int main() {
    int classSize = 5;
    Student students[classSize];
    for (int i=0; i<classSize; i++) {
        cout << "Enter First Name, Last Name, and test score \n";
        cin >> students[i];
    }
    cout << "Student Details:" << endl;
    printSequence(students, students+classSize);
    isort(students, students+classSize);
    cout << "Student Details After Sorting:" <<  students << endl;
    printSequence(students, students+classSize);
    return 1;
}
