#include<bits/stdc++.h>

using namespace std;

class Solution {
    int minFallingPathSum(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &dp) {
        if(dp[row][col] != INT_MAX) return dp[row][col];
        if(row == matrix.size() - 1) return dp[row][col] = dp[row][col];
        int left = INT_MAX, right = INT_MAX;
        if(col > 0) left = minFallingPathSum(matrix, row + 1, col - 1, dp);
        int straight = minFallingPathSum(matrix, row + 1, col, dp);
        if(col < matrix[0].size() - 1) right = minFallingPathSum(matrix, row + 1, col + 1, dp);
        dp[row][col] = min(left, min(straight, right)) + matrix[row][col];
        return dp[row][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size() == 1 || matrix[0].size() == 1) return matrix[0][0];
        int ans = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        for(int i = 0; i < matrix.size(); i++) ans = min(ans, minFallingPathSum(matrix, 0, i, dp));
        return ans;
    }
};

int main() {}