#include<iostream>
#include"isort.h"
#include"printSequence.h"
using namespace std;

void printNumbers(int *start, int *end) {
    int *current = start;
    while(current != end) {
        cout << *current << " ";
        current++;
    }
    cout << endl;
}
int main() {
    srand(time(NULL));
    int totalNumbers = 5;
    int array[totalNumbers];
    for(int i=0; i<totalNumbers; i++) {
        //cout << "Enter Numbers:";
        //cin >> array[i];
        array[i] = rand()%100;
    }
    cout << "Array Details Before Sorting:" << endl;
    printSequence(array, array+totalNumbers);
    isort(array, array+totalNumbers);
    cout << "Array Details After Soring:" << endl;
    printSequence(array, array+totalNumbers);
    printNumbers(array, array+totalNumbers);
    return 1;
}
