#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i = 0; i < k; i++) {
            happiness[i] = max(happiness[i] - i, 0);
            res+= happiness[i];
        }
        return res;
    }
};

int main() {}