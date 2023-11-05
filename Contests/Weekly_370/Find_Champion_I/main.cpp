#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            bool flag = true;
            for(int j = i + 1; j < grid.size(); j++) if(!grid[i][j]) {
                flag = false;
                break;
            }
            if(flag) return i;
        }
        return -1;
    }
};

int main() {}