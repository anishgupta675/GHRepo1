#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int n, int k) {
        if(!k) {
            ans.push_back(temp);
            return;
        }
        if(!n) return;
        dfs(n - 1, k);
        temp.push_back(n);
        dfs(n - 1, k - 1);
        temp.erase(temp.begin() + (temp.size() - 1));
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k);
        return ans;
    }
};

int main() {}