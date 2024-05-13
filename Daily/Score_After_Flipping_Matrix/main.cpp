#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            if(!grid[i][0]) {
                for(int j = 0; j < grid[i].size(); j++) grid[i][j] = (grid[i][j]) ? 0 : 1;
            }
        }
        for(int i = 0; i < grid[0].size(); i++) {
            int set_count = 0;
            for(int j = 0; j < grid.size(); j++) set_count+= grid[j][i];
            if(set_count < grid.size() - set_count) {
                for(int j = 0; j < grid.size(); j++) grid[j][i] = (grid[j][i]) ? 0 : 1;
            }
        }
        for(int i = 0; i < grid.size(); i++) for(int j = 0; j < grid[i].size(); j++) res+= (grid[i][j]) << (grid[i].size() - j - 1);
        return res;
    }
};

int main() {}