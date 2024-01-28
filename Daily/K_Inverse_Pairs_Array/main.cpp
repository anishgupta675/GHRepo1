#include<bits/stdc++.h>

using namespace std;

const int mod = int(1e9 + 7);

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);
        prev[0] = 1;
        curr[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; ++j) {
                curr[j] = (prev[j] + (j > 0 ? curr[j - 1] : 0)) % mod;
                curr[j] = (curr[j] + mod - (j >= i ? prev[j - i] : 0)) % mod;
            }
            prev = curr;
        }
        return curr[k];
    }
};

int main() {}