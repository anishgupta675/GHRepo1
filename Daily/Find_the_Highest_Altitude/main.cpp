#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur_sum = 0, max_sum = 0;
        for(int i : gain) {
            cur_sum+= i;
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum;
    }
};

int main() {}