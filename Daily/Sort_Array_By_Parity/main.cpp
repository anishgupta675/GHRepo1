#include<bits/stdc++.h>

using namespace std;

class Solution {
    void swap(int *xp, int *yp) {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int parity = 0;
        for(int i = 0; i < nums.size(); i++) if(!(nums[i] % 2)) swap(&nums[i], &nums[parity++]);
        return nums;
    }
};

int main() {}