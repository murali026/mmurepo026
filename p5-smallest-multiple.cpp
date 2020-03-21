#include<iostream>

using namespace std;

bool is_divisble_up_to_20(long num) {
    for(int i = 1; i < 21; ++i) {
        if(num%i != 0) {
            cout << num << " is not divisible by " << i << endl;
            return false;
        }
    }
    cout << num << " is divisible by all numbers up to 20" << endl;
    return true;
}

int main() {
    long num = 1;
    for(int i = 1; i < 21; ++i) {
        num *= i;
    }
    //i = 2520;
    cout << num << endl;
    for(int i = 1; i < 21; ++i) {
       if(is_divisble_up_to_20(num/i)) {
       }
    }
    cout << "Divide by 2" << endl;
    long n2 = 121645100408832000;
    for(int i = 1; i < 21; ++i) {
        n2 = n2/2;
        if(!is_divisble_up_to_20(n2)) {
            break;
        }
    }
    cout << "Lets Check all numbers" << endl;
    long n3 = 29698510842000;
    while(n3>0) {
        n3 = n3/3;
        cout << "divide by 3 " << endl;
        if(is_divisble_up_to_20(n3)) {
            break;
        }
    }
    long n4 = 9899503614000;
    long n5;
    while(n3>0) {
        n4 = n4/5;
        cout << "divide by 5-1 " << endl;
        if(is_divisble_up_to_20(n4)) {
            n5 = n4;
            break;
        }
    }
    cout << n5 << endl;
    long n6;
    while(n5>0) {
        n5 = n5/5;
        cout << "divide by 5" << endl;
        if(is_divisble_up_to_20(n5)) {
            n6 = n5;
            break;
        }
    }
    cout << n6 << endl;
    long n7 = n6/9;
    is_divisble_up_to_20(n7);
    is_divisble_up_to_20(n7/7);
    long n8 = n7/7;
    long n9 = n8-2;
    n9 = 20 * 19 * 18 * 17 * 14 * 13 * 11;
    while(true) {
        if(is_divisble_up_to_20(n9)) {
            break;
        }
        n9 -= 2;
    }
    return 0; 
    //answer - 232792560
}
