#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dir {
        {-2, -1},
        {-1, -2},
        {1, -2},
        {2, -1},
        {2, 1},
        {1, 2},
        {-1, 2},
        {-2, 1}
    };
    unordered_map<string, double> umap;
public:
    double knightProbability(int n, int k, int row, int column) {
        if(row < 0 || row >= n || column < 0 || column >= n) return 0;
        if(!k) return 1;
        double probability = 0;
        string key = "";
        if(umap.find(key) != umap.end()) return umap[key];
        for(int i = 0; i < dir.size(); i++) probability+= knightProbability(n, k - 1, row + dir[i][0], column + dir[i][1]) / 8.0f;
        return umap[key] = probability;
    }
};

int main() {}