#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++) for(int j = i + 1; j < nums.size(); j++) if(nums[i] == nums[j]) res++;
        return res;
    }
};

int main() {}