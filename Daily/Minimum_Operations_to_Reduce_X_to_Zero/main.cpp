#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0, curr_sum = 0, max_window = -1, l = 0;
        for(int i = 0; i < nums.size(); i++) target+= nums[i];
        target-= x;
        for(int i = 0; i < nums.size(); i++) {
            curr_sum+= nums[i];
            while(l <= i && curr_sum > target) {
                curr_sum-= nums[l];
                l++;
            }
            if(curr_sum == target) max_window = max(max_window, i - l + 1);
        }
        return (max_window == -1) ? -1 : nums.size() - max_window;
    }
};

int main() {}