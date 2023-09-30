#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        vector<int> pattern(nums.size());
        pattern[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) pattern[i] = min(pattern[i - 1], nums[i]);
        for(int i = 2; i < nums.size(); i++) for(int j = 0; j < i; j++) if(nums[i] < nums[j] && nums[i] > pattern[j]) return true;
        return false;
    }
};

int main() {}