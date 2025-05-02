#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> nums(dominoes.size(), 0);
        
        for (int i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i] == 'R') nums[i] = INT_MAX;
            if (dominoes[i] == 'L') nums[i] = INT_MIN;
        }
        
        for (int i = 0, prev = 0; i < nums.size(); ++i) {
            if (prev > 0 && nums[i] != INT_MAX && nums[i] != INT_MIN) 
                nums[i] = (prev == INT_MAX ? 1 : prev + 1);
            prev = nums[i];
        }
        
        for (int i = nums.size() - 1, prev = 0; i >= 0; --i) {
            if (prev < 0 && nums[i] != INT_MAX && nums[i] != INT_MIN) {
                prev = (prev == INT_MIN ? 0 : -prev);
                
                if (prev + 1 < nums[i] || nums[i] == 0) nums[i] = -prev - 1;
                else if (prev + 1 == nums[i]) nums[i] = 0;
            }
            prev = nums[i];
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) dominoes[i] = 'R';
            else if (nums[i] < 0) dominoes[i] = 'L';
        }
        
        return dominoes;
    }
};

int main() {}
