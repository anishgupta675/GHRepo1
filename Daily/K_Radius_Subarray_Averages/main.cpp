#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        if((2 * k + 1) > nums.size()) return ans;
        vector<long long> prefixSum(nums.size() + 1);
        for(int i = 0; i < nums.size(); ++i) prefixSum[i + 1] = prefixSum[i] + nums[i];
        for (int i = k; i + k < nums.size(); ++i) ans[i] = (prefixSum[i + k + 1] - prefixSum[i - k]) / (2 * k + 1);
        return ans;
    }
};

int main() {}