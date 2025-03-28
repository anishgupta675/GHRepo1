#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        vector<int> result(queries.size(), 0);
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int queryIndex = 0; queryIndex < queries.size(); queryIndex++) {
            int queryValue = queries[queryIndex];
            queue<pair<int, int>> bfsQueue;
            bfsQueue.push({0, 0});
            vector<vector<bool>> visited(rowCount,
                                         vector<bool>(colCount, false));
            visited[0][0] = true;
            int points = 0;
            while (!bfsQueue.empty()) {
                int queueSize = bfsQueue.size();
                while (queueSize--) {
                    auto [currentRow, currentCol] = bfsQueue.front();
                    bfsQueue.pop();
                    if (grid[currentRow][currentCol] >= queryValue) continue;
                    points++;
                    for (auto [rowOffset, colOffset] : DIRECTIONS) {
                        int newRow = currentRow + rowOffset,
                            newCol = currentCol + colOffset;
                        if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                            newCol < colCount && !visited[newRow][newCol] &&
                            grid[newRow][newCol] < queryValue) {
                            bfsQueue.push({newRow, newCol});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            result[queryIndex] = points;
        }
        return result;
    }
};

int main() {}
