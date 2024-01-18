#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> dp = vector<int>(100);
public:
    int climbStairs(int n) {
        if(n == 1) return dp[n] = 1;
        if(n == 2) return dp[n] = 2;
        if(dp[n]) return dp[n];
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {}