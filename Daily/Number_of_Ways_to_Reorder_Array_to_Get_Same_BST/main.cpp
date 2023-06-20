#include<bits/stdc++.h>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;
    vector<vector<long long>> pascal;
    int dfs(vector<int> &nums) {
        if (nums.size() <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < nums.size(); i ++){
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        return (((dfs(left) * pascal[nums.size() - 1][left.size()]) % MOD) * dfs(right)) % MOD;
    }
public:
    
    int numOfWays(vector<int>& nums) {
        pascal = vector<vector<long long>>(nums.size() + 1);
        for (int i = 0; i < nums.size() + 1; i ++){
            pascal[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; j ++) pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1]) % MOD;
        }
        return dfs(nums) - 1;
    }
};

int main() {}