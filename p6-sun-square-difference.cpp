#include<iostream>
using namespace std;

long sum_of_square(int num) {
    long sum = 0;
    for(int i = 1; i < num; ++i) {
        sum += (i * i);
    }
    return sum;
}

long square_of_sum(int num) {
    long sum = 0;
    for(int i = 1; i < num; ++i) {
        sum += i;
    }
    return sum*sum;
}

int main() {
    int  num = 101;
    cout << sum_of_square(num) << endl; 
    cout << square_of_sum(num) << endl;
    cout << square_of_sum(num)-sum_of_square(num) << endl;
    return 0;
}
