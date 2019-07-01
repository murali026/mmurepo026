#include<iostream>
#include"student.h"
#include"isort.h"
using namespace std;

int main() {
    srand(time(NULL));
    int totalNumbers = 5;
    int array[totalNumbers];
    int classSize = 5;
    Student students[classSize];
    for (int i=0; i<classSize; i++) {
        array[i] = rand()%100;
        cout << "Enter First Name, Last Name, and test score \n";
        cin >> students[i];
        cout << students[i];
    }
    cout << "Array Details Before Sorting:" <<  endl;
    printSequence(array, array+totalNumbers);
    cout << "Student Details Before Sorting:" << endl;
    printSequence(students, students+classSize);
    Less<Student> isLess;
    Less<int> isLessInt;
    Greater<Student> isGreater;
    Greater<int> isGreaterInt;
    isort(students, students+classSize, isGreater);
    isort(array, array+totalNumbers, isGreaterInt);
    //isort(students, students+classSize, isLess);
    //isort(array, array+totalNumbers, isLessInt);
    cout << "Array Details After Soring:" << endl;
    printSequence(array, array+totalNumbers);
    cout << "Student Details After Sorting:" << endl;
    printSequence(students, students+classSize);
    return 1;
}
