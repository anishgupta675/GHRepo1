#include<bits/stdc++.h>

using namespace std;

class Solution {
    double soupServings(int a, int b, unordered_map<int, double> &dp) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        int key = a * 5000 + b;
        if(dp.count(key)) return dp[key];
        return dp[key] = 0.25 * (soupServings(a - 4, b, dp) + soupServings(a - 3, b - 1, dp) + soupServings(a - 2, b - 2, dp) + soupServings(a - 1, b - 3, dp));
    }
public:
    double soupServings(int n) {
        if(n > 4800) return 1.0;
        unordered_map<int, double> dp;
        n = (n + 24) / 25;
        return soupServings(n, n, dp);
    }
};

int main() {}