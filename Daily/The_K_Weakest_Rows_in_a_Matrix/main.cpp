#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        vector<pair<int, int>> rowStrengths;
        for(int i = 0; i < mat.size(); ++i) rowStrengths.push_back({accumulate(mat[i].begin(), mat[i].end(), 0), i});
        sort(rowStrengths.begin(), rowStrengths.end());
        for(int i = 0; i < k; ++i) result.push_back(rowStrengths[i].second);
        return result;
    }
};

int main() {}