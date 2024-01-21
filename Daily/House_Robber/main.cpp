#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int rob0 = nums[0], rob1 = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            int rob2 = max(nums[i] + rob0, rob1);
            rob0 = rob1;
            rob1 = rob2;
        }
        return rob1;
    }
};

int main() {}