#include<bits/stdc++.h>

using namespace std;

class Solution {
    int getLDSSize(vector<int> &nums, vector<int> &dp) {
        sort(nums.begin(), nums.end());
        int lds_size = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(!(nums[i] % nums[j])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    lds_size = max(lds_size, dp[i]);
                }
            }
        }
        return lds_size;
    }
    vector<int> constructLDS(vector<int> &nums, vector<int> &dp, int lds_size) {
        int prev = -1;
        vector<int> lds;
        for(int i = dp.size() - 1; i >= 0; i--) {
            if(dp[i] == lds_size && (prev == -1 || !(prev % nums[i]))) {
                lds.push_back(nums[i]);
                lds_size--;
                prev = nums[i];
            }
        }
        return lds;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        return constructLDS(nums, dp, getLDSSize(nums, dp));
    }
};

int main() {}
