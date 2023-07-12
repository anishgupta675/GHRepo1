#include<bits/stdc++.h>

using namespace std;

class Solution {
    bool eventualSafeNodes(int index, vector<bool>& vis, vector<vector<int>>& graph, vector<int>& unsafe) {
        bool safe = true;
        for(int neighbor : graph[index]) {
            if(vis[neighbor] || unsafe[neighbor] == 2) {
                safe = false;
                break;
            }
            if(unsafe[neighbor] == 1) continue;
            vis[neighbor] = true;
            if(!eventualSafeNodes(neighbor, vis, graph, unsafe)) safe = false;
            vis[neighbor] = false;
        }
        unsafe[index] = safe ? 1 : 2;
        return safe;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(), false);
        vector<int> unsafe(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++) {
            if (unsafe[i] == 0) {
                vis[i] = true;
                eventualSafeNodes(i, vis, graph, unsafe);
                vis[i] = false;
            }
        }
        vector<int> res;
        for(int i = 0; i < unsafe.size(); i++) if(unsafe[i] == 1) res.push_back(i);
        return res;
    }
};

int main() {}