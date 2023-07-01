#include<bits/stdc++.h>

using namespace std;

class Solution {
    int ans = INT_MAX;
    void helper(int start, const vector<int>& cookies, vector<int>& temp, int k) {
        if(start == cookies.size()) {
            int max_i = INT_MIN;
            for(int i = 0; i < k; i++) max_i = max(max_i, temp[i]);
            ans = min(ans, max_i);
            return;
        }
        for(int i = 0; i < k; i++) {
            temp[i]+= cookies[start];
            helper(start + 1, cookies, temp, k);
            temp[i]-= cookies[start];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k, 0);
        helper(0, cookies, temp, k);
        return ans;
    }
};

int main() {}