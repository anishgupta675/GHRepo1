#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(int i, vector<vector<int>> &gr, vector<int> &vis, vector<int> &comp) {
        if(vis[i]) return;
        vis[i] = 1;
        comp.push_back(i);
        for(auto j: gr[i])
            if(!vis[j]) dfs(j, gr, vis, comp);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n, vector<int>());
        for(auto i : edges) {
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        int ans = 0;
        vector<int> vis(n);
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1) continue;
            vector<int> comp;
            dfs(i, gr, vis, comp);
            int ed = 0;
            for(auto v: comp) ed += gr[v].size();
            int cs = comp.size();
            if(ed == (cs * (cs - 1))) ans++;
        }
        return ans;
    }
};

int main() {}
