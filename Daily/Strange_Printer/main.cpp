#include<bits/stdc++.h>

using namespace std;

class Solution {
    int **dp = nullptr;
    int strangePrinter(string s, int low, int high) {
        if(low > high) return 0;
        if(low == high) return 1;
        if(dp[low][high] != -1) return dp[low][high];
        dp[low][high] = 1 + strangePrinter(s, low + 1, high);
        for(int i = low; i < high; i++) if(s[low] == s[i + 1]) dp[low][high] = min(dp[low][high], strangePrinter(s, low + 1, i) + strangePrinter(s, i + 1, high));
        return dp[low][high];
    }
public:
    int strangePrinter(string s) {
        dp = (int **)malloc(s.length() * sizeof(int *));
        for(int i = 0; i < s.length(); i++) {
            dp[i] = (int *)malloc(s.length() * sizeof(int));
            for(int j = 0; j < s.length(); j++) dp[i][j] = -1;
        }
        return strangePrinter(s, 0, s.length() - 1);
    }
};

int main() {}