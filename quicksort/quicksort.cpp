#include<iostream>
#include"../array/array.h"
#include"../student/printSequence.h"
#include"../student/predicates.h"
//#include"../student/swap.h"

using namespace std;

void swap(int& a, int& b)
{
    if(a == b) {
        return;
    }
    cout << "\tSwap:" << a << " and " << b << endl;
    int c = a;
    a = b;
    b = c;
}

template <class Iter, class Predicate>
Iter partition(Iter begin, Iter end, Predicate predicate) {
    cout << endl << "Partition Begin:" << endl;
    Iter pivot = end;
    Iter x = begin;
    --pivot;
    --x;
    for(Iter y=begin; y!=end; ++y) {
        if(predicate(*y, *pivot)) {
            ++x;
            swap(*y, *x);
        }
    }
    ++x;
    swap(*x, *pivot);
    cout << endl << "Partition End:" << endl;
    printSequence(begin, end);
    return x;
};

template <class Iter, class Predicate>
void qsort(Iter begin, Iter end, Predicate predicate) {
    if(end-begin>1) {
        Iter pivot = partition(begin, end, predicate);
        qsort(begin, pivot, predicate);
        qsort(++pivot, end, predicate);
    }
};

int main() {
    typedef Array<int, 7> Array;
    Array a;
    a[0] = 5;
    a[1] = 7;
    a[2] = 6;
    a[3] = 1;
    a[4] = 3;
    a[5] = 2;
    a[6] = 4;
    Less<int> isLess;
    cout << "Original List: ";
    printSequence(a.begin(), a.end());
    cout << endl;
    //cout << "Front Element is: " << a.front() << endl;
    //cout << "Back Element is: " << a.end() << endl;
    int a2[9];
    a2[0] = 3;
    a2[1] = 5;
    a2[2] = 8;
    a2[3] = 1;
    a2[4] = 2;
    a2[5] = 9;
    a2[6] = 4;
    a2[7] = 7;
    a2[8] = 6;
    //qsort(a2, a2+9, isLess);
    //printSequence(a2, a2+9);
    qsort(a.begin(), a.end(), isLess);
    cout << "Sequence After Quick Sort:" << endl;
    //printSequence(a2, a2+9);
    printSequence(a.begin(), a.end());
    cout << endl;
    return 1;
}
