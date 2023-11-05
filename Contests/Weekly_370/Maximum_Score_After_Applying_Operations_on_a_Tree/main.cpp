#include<bits/stdc++.h>

using namespace std;

class Solution {
    pair<long long, long long> dfs(vector<vector<int>> &tree, vector<int> &values, int node, int parent) {
        long long leftout = 0, taken = 0;
        for(int i = 0; i < tree[node].size(); i++) {
            if(tree[node][i] == parent) continue;
            pair<int, int> tl = dfs(tree, values, tree[node][i], node);
            taken+= tl.first;
            leftout+= tl.second;
        }
        taken+= (leftout) ? max(leftout, (long long)values[node]) : 0;
        leftout = (leftout) ? min(leftout, (long long)values[node]) : values[node];
        return make_pair(taken, leftout);
    }
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> tree(values.size());
        for(int i = 0; i < edges.size(); i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(tree, values, 0, -1).first;
    }
};

int main() {}