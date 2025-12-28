#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countNegatives(vector<vector<int>> &grid) {
		int r = grid.size(), c = grid[0].size(), i = r - 1, j = 0, count = 0;
		while(i >= 0 && j < c) {
			if(grid[i][j] < 0) {
				count += (c - j);
				i--;
			} else j++;
		}
		return count;
	}
};

int main() {}
