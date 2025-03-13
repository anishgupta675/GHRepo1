#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>> &queries, int k) {
        int sum = 0;
        vector<int> differenceArray(nums.size() + 1);
        for(int i = 0; i < k; i++) {
            int start = queries[i][0], end = queries[i][1], val = queries[i][2];
            differenceArray[queries[i][0]] += queries[i][2];
            differenceArray[queries[i][1] + 1] -= queries[i][2];
        }
        for(int i = 0; i < nums.size(); i++) {
            sum += differenceArray[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        if(!canFormZeroArray(nums, queries, right)) return -1;
        while(left <= right) {
            int middle = left + (right - left) >> 1;
            if(canFormZeroArray(nums, queries, middle)) right = middle - 1;
            else left = middle + 1;
        }
        return left;
    }
};

int main() {}
