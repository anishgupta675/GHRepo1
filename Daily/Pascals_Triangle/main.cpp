#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        res[0].push_back(1);
        for(int i = 1; i < numRows; i++) {
            for(int j = 0; j <= i; j++) {
                if(!j || j == i) res[i].push_back(1);
                else res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
        }
        return res;
    }
};

int main() {}