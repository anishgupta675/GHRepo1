#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), cnt(nums.size(), 1);
        int maxi = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                } else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) cnt[i]+= cnt[prev];
            }
            maxi = max(maxi, dp[i]);
        }
        int nos = 0;
        for(int i = 0; i < nums.size(); i++) if(dp[i] == maxi) nos+= cnt[i];
        return nos;
    }
};

int main() {}