#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int min_val = 0, min_indegree = 0;
        vector<int> indegree(n, 0);
        for(int i = 0; i < edges.size(); i++) {
            // cout << edges[i][1] << " = " << indegree[edges[i][1]] << endl;
            indegree[edges[i][1]]++;
            // cout << edges[i][1] << " = " << indegree[edges[i][1]] << endl;
            if(indegree[edges[i][1]] < min_val) {
                min_val = indegree[edges[i][1]];
                min_indegree = edges[i][1];
            }
        }
        // for(int i = 0; i < indegree.size(); i++) cout << i << " = " << indegree[i] << endl;
        for(int i = 0; i < indegree.size(); i++) {
            // cout << i << " = " << indegree[i] << endl;
            if(indegree[i] <= min_val) {
                min_val = indegree[i];
                min_indegree = i;
                // cout << min_indegree << " = " << min_val << endl;
            }
        }
        // cout << min_indegree << " = " << min_val << endl;
        for(int i = 0; i < indegree.size(); i++) if(indegree[i] == min_val && i != min_indegree) return -1;
        return min_indegree;
    }
};

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    Solution sol;
    for(int i = 0; i < e; i++) cin >> edges[i][0] >> edges[i][1];
    cout << sol.findChampion(v, edges) << endl;
}