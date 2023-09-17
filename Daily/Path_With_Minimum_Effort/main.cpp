#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> dr{-1, 0, 1, 0};
        vector<int> dc{0, 1, 0, -1};
        vector<vector<int>> dist(heights.size(), vector<int>(heights.size(), 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if(it.second.first == heights.size() - 1 && it.second.second == heights[0].size() - 1) return it.first;
            for(int i = 0; i < 4; i++) {
                if(it.second.first + dr[i] >= 0 && it.second.first + dr[i] < heights.size() && it.second.second + dc[i] < heights[0].size()) {
                    if(max(abs(heights[it.second.first][it.second.second] - heights[it.second.first + dr[i]][it.second.second + dc[i]]), it.first) < dist[it.second.first + dr[i]][it.second.second + dc[i]]) {
                        dist[it.second.first + dr[i]][it.second.second + dc[i]] = max(abs(heights[it.second.first][it.second.second] - heights[it.second.first + dr[i]][it.second.second + dc[i]]), it.first);
                        pq.push({max(abs(heights[it.second.first][it.second.second] - heights[it.second.first + dr[i]][it.second.second + dc[i]]), it.first), {it.second.first + dr[i], it.second.second + dc[i]}});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {}