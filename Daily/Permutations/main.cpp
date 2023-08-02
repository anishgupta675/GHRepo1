#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> res;
    void permute(vector<int> &nums, vector<int> &temp) {
        if(temp.size() == nums.size()) res.push_back(temp);
        else {
            for(int i = 0; i < nums.size(); i++) {
                if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
                temp.push_back(nums[i]);
                permute(nums, temp);
                temp.erase(temp.begin() + temp.size() - 1);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        permute(nums, temp);
        return res;
    }
};

int main() {}