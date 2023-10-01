#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word, ans = "";
        stringstream ss(s);
        while(ss >> word) {
            reverse(word.begin(), word.end());
            ans+= word + " ";
        }
        ans.pop_back();
        return ans;
    }
};

int main() {}