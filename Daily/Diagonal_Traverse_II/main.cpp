#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int i = 0, j = 0, k = 0;
        vector<int> res;
        while(k < nums.size()) {
            while(i >= 0 && j < nums.size()) {
                res.push_back(nums[i][j]);
                i--;
                j++;
            }
            k++;
            i = k;
            j++;
        }
        return res;
    }
};

int main() {}