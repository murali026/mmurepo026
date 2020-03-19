#include<iostream>
using namespace std;

int main() {
    int max_fib = 4000000;
    long sum_even = 0;
    long fib[2] = {1,2};
    bool run = true;
    while(run) {
        //cout << "," << fib[0];
        //cout << "," << fib[1];
        if((fib[0]%2) == 0) {
            cout << "Adding " << fib[0] << endl;
            sum_even += fib[0];
        }
        if((fib[1]%2) == 0) {
            cout << "Adding " << fib[1] << endl;
            sum_even += fib[1];
        }
        fib[0] = fib[1] + fib[0];
        fib[1] = fib[1] + fib[0];
        if(fib[0] > max_fib) {
            run = false;
        }
        if(fib[1] > max_fib) {
            run = false;
        }
    }
    cout << endl << "SUM OF EVEN FIB:" << sum_even << endl;
    return 0;
}
