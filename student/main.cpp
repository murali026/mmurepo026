#include<iostream>
#include"student.h"
#include"isort.h"
#include"printSequence.h"
#include"student_predicates.h"
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
    cout << endl << "Sort in Descending Order" << endl;
    isort(students, students+classSize, isGreater);
    isort(array, array+totalNumbers, isGreaterInt);
    printSequence(array, array+totalNumbers);
    printSequence(students, students+classSize);
    cout << "Sort in Ascending Order" << endl;
    isort(students, students+classSize, isLess);
    isort(array, array+totalNumbers, isLessInt);
    printSequence(array, array+totalNumbers);
    printSequence(students, students+classSize);

    cout << endl << "Sort by FirstName Ascending" << endl;
    isort(students, students+classSize, LessByFirstName());
    printSequence(students, students+classSize);
    cout << endl << "Sort by firstName Descending" << endl;
    isort(students, students+classSize, GreaterByFirstName());
    printSequence(students, students+classSize);
    cout << endl << "Sort by test score Ascending" << endl;
    isort(students, students+classSize, LessByTestScore());
    printSequence(students, students+classSize);
    cout << endl << "Sort by test score Descending" << endl;
    isort(students, students+classSize, GreaterByTestScore());
    printSequence(students, students+classSize);
    return 1;
}
