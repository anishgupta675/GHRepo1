#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int S = 0, S2 = 0;
    for(int i : nums) {
        S+= i;
        S2+= i * i;
    }
    return (int)(((S - ((nums.size() * (nums.size() + 1)) / 2)) + (S2 - ((nums.size() * (nums.size() + 1) * (2 * nums.size() + 1)) / 6))) / 2);
    }
};

int main() {}