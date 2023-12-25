#include<bits/stdc++.h>

using namespace std;

class Solution {
    int ways(int i, string s, vector<int> &dp) {
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int x = ways(i + 1, s, dp), y = 0;
        if(i < s.length() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) y+= ways(i + 2, s, dp);
        return dp[i] = x + y;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, -1);
        return ways(0, s, dp);
    }
};

int main() {}