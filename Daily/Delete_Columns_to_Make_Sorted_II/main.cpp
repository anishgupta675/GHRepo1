#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        vector<string> curr(strs.size());
        for(int i = 0; i < strs[0].length(); i++) {
            vector<string> curr2 = curr;
            for(int j = 0; j < strs.size(); j++) {
                curr2[j] += strs[j][i];
            }
            if(is_sorted(curr2.begin(), curr2.end())) {
                curr = curr2;
            } else res++;
        }
        return res;
    }
};

int main() {}