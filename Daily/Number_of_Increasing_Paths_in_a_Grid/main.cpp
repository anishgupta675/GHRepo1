#include<bits/stdc++.h>

using namespace std;

class Solution {
    int MOD = 1000000007;
    int Helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp, int prev) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || prev >= grid[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (1 + Helper(grid, i - 1, j, dp, grid[i][j]) + Helper(grid, i + 1, j, dp, grid[i][j]) + Helper(grid, i, j + 1, dp, grid[i][j]) + Helper(grid, i, j - 1, dp, grid[i][j])) % MOD;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        if(grid.size() == 1 && grid[0].size() == 1) return 1;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(dp[i][j] == -1) ans = (ans + Helper(grid, i, j, dp, -1)) % MOD;
                else ans = (ans + dp[i][j]) % MOD;
            }
        }
        return ans;
    }
};

int main() {}