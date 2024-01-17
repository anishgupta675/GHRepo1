#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost_map;
        for(int i = 0; i < matches.size(); i++) lost_map[matches[i][1]];
        vector<int> notLost;
        vector<int> onceLost;
        for(int i = 0; i < matches.size(); i++) {
            if(lost_map.find(matches[i][0]) == lost_map.end()) {
                notLost.push_back(matches[i][0]);
                lost_map[matches[i][0]] = 2;
            }
            if(lost_map[matches[i][1]] == 1) onceLost.push_back(matches[i][1]);
        }
        sort(notLost.begin(), notLost.end());
        sort(onceLost.begin(), onceLost.end());
        return { notLost, onceLost };
    }
};

int main() {}