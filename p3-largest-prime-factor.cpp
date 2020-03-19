#include<iostream>
#include<set>

using namespace std;

bool is_prime(long num) {
    long i = 2;
    long cur = num;
    while(i < cur) {
        if(num%i == 0) {
            return false;
        }
        i++;
    }
    cout << num << " is a prime" << endl;
    return true;
}

bool factors(long num, set<long>& fSet) {
    long cur = num;
    long i = 2;
    while(i <= cur) {
        if(num%i == 0) {
            long fact = num/i;
            cur = fact;
            cout << i << " and " << fact << " are factors" << endl;
            is_prime(cur);
            is_prime(i);
            fSet.insert(i);
            fSet.insert(cur);
        }
        i++;
    }
    return true;
}

int main() {
    long int num = 600851475143;
    //long int num = 13195;
    set<long> factorSet;
    factors(num, factorSet);
    return 0;
}
