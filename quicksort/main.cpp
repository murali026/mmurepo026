#include<iostream>
#include"../student/printSequence.h"
using namespace std;

#if 0
void swap(int* a, int* b)
{
    int* c = a;
    *a = *b;
    *b = *c;
}
#endif

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

static int pcount = 0;
int* partition(int* begin, int* end) {
    pcount++;
    cout << endl << "Partition Begin:" << pcount << endl;
    int* pivot = end;
    int* x = begin;
    --pivot;
    --x;
    for(int* y=begin; y!=end; ++y) {
        if(*y < *pivot) {
            ++x;
            swap(*y, *x);
        }
    }
    ++x;
    swap(*x, *pivot);
    cout << endl << "Partition End:" << pcount << endl;
    printSequence(begin, end);
    return x;
};

void qsort(int* begin, int* end) {
    if (end - begin > 1) {
        int* pivot = partition(begin, end);
        qsort(begin, pivot);
        qsort(++pivot, end);
    }
};

int main() {
    int a[9];
    /*a[0] = 5;
    a[1] = 7;
    a[2] = 6;
    a[3] = 1;
    a[4] = 3;
    a[5] = 2;
    a[6] = 4;*/
    a[0] = 3;
    a[1] = 5;
    a[2] = 8;
    a[3] = 1;
    a[4] = 2;
    a[5] = 9;
    a[6] = 4;
    a[7] = 7;
    a[8] = 6;
    cout << "Original List: ";
    printSequence(a, a+9);
    cout << endl;
    cout << "Performing Quick Sort:" << endl;
    qsort(a, a+9);
    cout << "Sequence after Quick Sort:" << endl;
    printSequence(a, a+9);
    cout << endl;
    return 1;
}
