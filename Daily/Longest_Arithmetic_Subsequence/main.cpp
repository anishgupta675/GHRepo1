#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int longest = 2;
        vector<unordered_map<int, int>> dp(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                longest = max(longest, dp[i][diff]);
            }
        }
        return longest;
    }
};

int main() {}