#include<bits/stdc++.h>

using namespace std;

class Solution {
    int uniquePaths(vector<vector<int>> &dp, int m, int n) {
        if(m < 0 || n < 0) return 0;
        if(!m && !n) return 1;
        if(dp[m][n]) return dp[m][n];
        return dp[m][n] = uniquePaths(dp, m, n - 1) + uniquePaths(dp, m - 1, n);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        return uniquePaths(dp, m, n);
    }
};

int main() {}