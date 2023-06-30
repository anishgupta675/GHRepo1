#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(make_pair(v, succProb[i]));
            adj[v].push_back(make_pair(u, succProb[i]));
        }
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(pair<int, double> x : adj[curr]) {
                if(dist[curr] * x.second > dist[x.first]) {
                    dist[x.first] = dist[curr] * x.second;
                    q.push(x.first);
                }
            }
        }
        return dist[end];
    }
};

int main() {}