#include<iostream>
#include<vector>
using namespace std;

static long max_num = 0;

bool is_palindrome(long i, long j) {
    vector<int> digits;
    digits.reserve(32);
    long num = i * j;
    long cur = num;
    while(cur > 0) {
        int mod = (cur%10);
        cur = cur/10;
        //cout << cur << " " << mod << endl;
        digits.push_back(mod);
    }
    for(int i = 0; i < digits.size()/2; ++i) {
       int j = digits.size()-i-1;
       if(digits[i] != digits[j]) {
           //cout << num << " is NOT A PALINDROME" << endl;
           return false;
       }
    }
    cout << num << " is A PALINDROME" << endl;
    if(num > max_num) {
        max_num = num;
    }
    return true;
}

int main() {
    int num = 999;
    int loop_count = 0;
    for(int i = num; i >= 1; --i) {
        for(int j = j-1; j >= 1; --j) {
            if(is_palindrome(i,j)) {
                loop_count++;
                cout << i << "x" << j << "=" << i*j << " is a palindrome" << endl;
            }
        }
    }
    cout << max_num << " is the biggest palindrome loop:" << loop_count << endl;
    return 0;
}
