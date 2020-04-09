#include<iostream>
#include<fstream>

using namespace std;

bool is_prime_number(long num) {
   for(long i = 2; i < num; ++i) {
       if(num%i == 0) {
           return false;
       }
   }
   return true;
}

long list_prime_numbers(int num) {
    int count = 0;
    long last_prime_number = 2;
    bool status = true;
    ofstream ofs("p7-prime.txt", ofstream::out);
    while(true) {
        if(is_prime_number(last_prime_number)) {
            cout << "Count: " << count << " PrimeNumber: " << last_prime_number << endl;
            ofs << "Count: " << count << " PrimeNumber: " << last_prime_number << endl;
            count++;
        }
        if(count >= num) {
            return last_prime_number;
        }
        last_prime_number += 1;
        if(last_prime_number%2==0) {
            last_prime_number += 1;
        }
        //cout << "Current Number: " << last_prime_number << endl;
    }
    ofs.close();
    return 0;
}

int main() {
    int pnum = 10001;
    //pnum = 10;
    list_prime_numbers(pnum);
    return 0;
}
