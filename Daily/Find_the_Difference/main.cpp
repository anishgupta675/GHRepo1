#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_set<char> uset;
        // for(int i = 0; i < s.length(); i++) uset.insert(s[i]);
        // for(int i = 0; i < t.length(); i++) if(uset.find(t[i]) == uset.end()) return t[i];
        // return '\0';
        unordered_map<char, int> umap;
        for(int i = 0; i < s.length(); i++) umap[s[i]]++;
        for(int i = 0; i < t.length(); i++) {
            if(!umap[t[i]]) return t[i];
            umap[t[i]]--;
        }
        return '\0';
    }
};

int main() {}