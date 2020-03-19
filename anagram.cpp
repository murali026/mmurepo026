#include <bits/stdc++.h>
#include <map>
#include<assert.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int check_anagram(string &s1, string& s2) {
    map<char,int> anagramMap;
    for(int i=0; i < s1.length(); ++i) {
        map<char, int>::iterator it = anagramMap.find(s1[i]);
        if(it != anagramMap.end()) {
            ++it->second;
        } else {
            anagramMap[s1[i]] = 1;
        }
    }
    for(int i=0; i<s2.length(); ++i) {
        map<char, int>::iterator it = anagramMap.find(s2[i]);
        if(it != anagramMap.end()) {
            --it->second;
            if(it->second == 0) {
                it = anagramMap.erase(it);
            }
        } else {
            return false;
        }
    }
    if (anagramMap.empty()) {
        return true;
    }
    return false;
};

int check_anagram_vector(string &s1, string &s2) {
    char buf[256];
    memset(buf, 0, sizeof(buf));
    for(int i=0; i<s1.length(); ++i) {
        buf[s1[i]] += 1;
    }
    for(int j=0; j<s2.length(); ++j) {
        if(buf[s2[j]] == 0) {
            return 0;
        } else {
            buf[s2[j]] -= 1;
        }
    }
    for(int i=0;i<s1.length();++i) {
        if(buf[s1[i]] != 0) {
            return 0;
        }
    }
    return 1; 
}

int compare_str(string& s, int groupcount) {
    int count = 0;
    for(int i=0; i < s.length(); ++i) {
        for(int j=i+1; j<s.length();++j) {
            string s1(s,i,groupcount);
            string s2(s,j,groupcount);
            //cout << s1 << "," << s2 << endl;
            //count += check_anagram(s1,s2);
            count += check_anagram_vector(s1,s2);
        }
    }
    return count;
}

int sherlockAndAnagrams(string s) {
    int pair_count = 0;
    //cout << "InputString:" << s << endl;
    map<char, int> letterMap;
    bool unique = true;
    for(int i=0; i < s.length(); ++i) {
        map<char, int>::iterator it = letterMap.find(s[i]);
        if(it == letterMap.end()) {
            //letter not found in map
            letterMap[s[i]] = 1;
        } else {
            ++it->second;
            unique = false;
        }
    }
    for(map<char,int>::iterator it=letterMap.begin(); it!=letterMap.end();) {
        if(it->second == 1) {
            it = letterMap.erase(it);
        } else {
            ++it;
        }
    }
    /*for(map<char,int>::iterator it=letterMap.begin(); it!=letterMap.end();++it) {
        cout << it->first << it->second << endl;
    }*/
    if(unique) {
        return 0;
    }
    for(int i = 0 ; i < s.length(); ++i) {
        for (int j = i+1; j < s.length();++j) {
            if (s[i] == s[j]) {
                //cout << "(" << i << "," << j << "):" << s[i] << endl;
                pair_count++;
            }
        }
    }
    //cout << "PairCount After first byte comparision:" << pair_count << endl;
    for(int i=2; i < s.length(); ++i) {
        pair_count += compare_str(s, i);
    }
    return pair_count;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << endl;
    }

    return 0;
}
