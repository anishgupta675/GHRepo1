#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int i = 0;
        string res = "";
        unordered_map<char, int> freq_map;
        for(int j = 0; j < s.length(); j++) freq_map[s[j]]++;
        for(int j = 0; j < s.length(); j++) res+= ' ';
        for(int j = 0; j < s.length(); j++) {
            for(int k = 0; k < freq_map[k]; k++) {
                if(i >= s.length()) i = 1;
                res[i] = s[j];
                i+= 2;
            }
        }
        return res;
    }
};

int main() {}