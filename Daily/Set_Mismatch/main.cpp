#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x = 0, sum = 0, orig_sum = (nums.size() * (nums.size() + 1)) >> 1;
        unordered_map<int, int> umap;
        for(int i : nums) {
            umap[i]++;
            sum+= i;
            if(umap[i] == 2) x = i;
        }
        return {x, orig_sum - sum + x};
    }
};

int main() {}