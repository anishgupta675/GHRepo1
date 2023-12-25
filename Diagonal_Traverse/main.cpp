#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool flag = 0;
        int i = 0, j = 0;
        vector<int> res;
        while(i != mat.size() - 1 && j != mat[i].size() - 1) {
            if(flag) {
                while(i < mat.size() && j > 0) {
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                j++;
            } else {
                while(i > 0 && j < mat[i].size()) {
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            flag^= 1;
        }
        return res;
    }
};

int main() {}