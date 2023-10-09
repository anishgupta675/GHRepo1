#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> res = vector<int>(2, -1);
    void findFirstIndex(vector<int> &nums, int low, int high, int target) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(nums[mid] >= target) findFirstIndex(nums, low, mid - 1, target);
        else findFirstIndex(nums, mid + 1, high, target);
        if(nums[mid] == target) res[0] = mid;
    }
    void findSecondIndex(vector<int> &nums, int low, int high, int target) {
        if(low > high) return;
        int mid = (low + high) >> 1;
        if(nums[mid] <= target) findSecondIndex(nums, low, mid - 1, target);
        else findSecondIndex(nums, mid - 1, high, target);
        if(nums[mid] == target) res[1] = mid;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        findFirstIndex(nums, 0, nums.size() - 1, target);
        findSecondIndex(nums, 0, nums.size() - 1, target);
        return res;
    }
};

int main() {}