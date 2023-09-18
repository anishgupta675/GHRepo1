#include<bits/stdc++.h>

using namespace std;

struct comp {
    constexpr bool operator() {
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept {
            if(a.first > b.first) return true;
            if(a.first < b.first) return false;
            return a.second > b.second;
        }
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for(int i = 0; i < mat.size(); i++) pq.push(make_pair(upper_bound(mat[i], mat[i] + mat[i].size(), 1, greater<int>()), i));
        for(int i = 0; i < k; i++) {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};

int main() {}