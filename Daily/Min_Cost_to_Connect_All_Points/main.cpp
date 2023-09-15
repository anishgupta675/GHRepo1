#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        unordered_set<int> vis;
        priority_queue<pair<int, int>> min_heap;
        vector<vector<pair<int, int>>> adj(points.size(), vector<pair<int, int>>());
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                adj[i].push_back(make_pair(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), j));
                adj[j].push_back(make_pair(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i));
            }
        }
        min_heap.push(make_pair(0, 0));
        while(vis.size() < points.size()) {
            int cost = min_heap.top().first, i = min_heap.top().second;
            min_heap.pop();
            if(vis.find(i) == vis.end()) {
                res+= cost;
                vis.insert(i);
                for(pair<int, int> j : adj[i]) if(vis.find(j.second) == vis.end()) min_heap.push(j);
            }
        }
        return res;
    }
};

int main() {}