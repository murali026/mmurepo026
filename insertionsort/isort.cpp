#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    cout << __func__ << ":" << __LINE__ << ":swap->" << *a << " and " << *b << endl;
    int c = *a;
    *a = *b;
    *b = c;
    cout << __func__ << ":" << __LINE__ << ":swapdone->" << *a << " and " << *b << endl;
}

void isort(int *start, int *end) {
    for(int *cur = start; cur != end; ++cur) {
        int c1 = 1;
        cout << __func__ << ":" << __LINE__ << ": ExternalCount:"<< c1 << endl;
        int *x = cur;
        int *y = cur;
        --x;
        while((y != start) && (*y > *x)) {
            int c2 = 1;
            cout << __func__ << ":" << __LINE__ << ": InternalCount:"<< c2 << endl;
            swap(y, x);
            --x;
            --y;
            c2++;
        }
        c1++;
    }
}

void printNumbers(int *start, int *end) {
    int *current = start;
    while(current != end) {
        cout << *current << " ";
        current++;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int totalNumbers = 5;
    int array[totalNumbers];
    for(int i=0; i<totalNumbers; i++) {
        //cout << "Enter Numbers:";
        //cin >> array[i];
        array[i] = rand()%100;
    }
    cout << "Array Details:" << endl;
    printNumbers(array, array+totalNumbers);
    isort(array, array+totalNumbers);
    cout << "After InsertionSort:" << endl;
    printNumbers(array, array+totalNumbers);
    return 1;
}
