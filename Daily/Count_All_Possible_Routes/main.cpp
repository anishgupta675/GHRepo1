#include<bits/stdc++.h>

using namespace std;

class Solution {
    const int MOD = 1000000007;
    int helper(const vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp) {
        if(fuel < 0) return 0;
        if(dp[start][fuel] != -1) return dp[start][fuel];
        int total = start == finish ? 1 : 0;
        for(int i = 0; i < locations.size(); i++) if(i != start && fuel >= abs(locations[i] - locations[start])) total = (total + helper(locations, i, finish, fuel - abs(locations[i] - locations[start]), dp)) % MOD;
        return dp[start][fuel] = total;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int>(fuel + 1, -1));
        return helper(locations, start, finish, fuel, dp);
    }
};

int main() {}