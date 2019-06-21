#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubblesort(int *start, int totalNumbers) {
    if(start && totalNumbers) {
        int *end = start + totalNumbers-1;
        int* cur = start;
        for(int i=0; i<totalNumbers-1; i++) {
            //int c1 = 1;
            //cout << "External" << ":" << c1 << endl;
            int* x = cur;
            int* y = cur+1;
            while(y <= end) {
                //int c2 = 1;
                //cout << "Internal" << ":" << c2 << endl;
                //if(*y > *x) { //descending order
                if(*y < *x) { //ascending order
                    swap(y,x);
                }
                ++x;
                ++y;
                //c2++;
            }
            ++start;
            --end;
            //c1++;
        }
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
    bubblesort(array, totalNumbers);
    cout << "After BubbleSort:" << endl;
    printNumbers(array, array+totalNumbers);
    return 1;
}
