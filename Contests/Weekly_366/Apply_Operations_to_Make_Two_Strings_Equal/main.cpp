#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int res = 0, cntZeroes = 0, hamDist = 0, unpaired = -1, cur_unpaired = -1;
        vector<int> parity;
        vector<bool> vis(s1.length());
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i = 0; i < s1.length(); i++) {
            if(!s1[i]) cntZeroes++;
            if(!s2[i]) cntZeroes--;
            if(s1[i] != s2[i]) {
                hamDist++;
                parity.push_back(i);
                cout << "Parity Bit: " << i << endl;
            }
        }
        if((cntZeroes % 2) || (hamDist % 2)) return -1;
        for(int i = 1; i < parity.size(); i++) pq.push({parity[i] - parity[i - 1], {i - 1, i}});
        while(!pq.empty()) {
            pair<int, pair<int, int>> cur = pq.top();
            pq.pop();
            if(vis[cur.second.first] || vis[cur.second.second]) {
                if(unpaired) {
                    cur_unpaired = (vis[cur.second.first]) ? cur.second.second : cur.second.first;
                    res+= min(x, cur_unpaired - unpaired);
                    vis[cur_unpaired] = 1;
                    vis[unpaired] = 1;
                } else unpaired = (vis[cur.second.first]) ? cur.second.second : cur.second.first;
            } else {
                res+= min(cur.first, x);
                vis[cur.second.first] = 1;
                vis[cur.second.second] = 1;
            }
        }
        cout << "Final Result: " << res << endl;
        return res;
    }
};

int main() {
    int x;
    string s1, s2;
    Solution sol;
    getline(cin, s1);
    getline(cin, s2);
    cin >> x;
    cout << sol.minOperations(s1, s2, x) << endl;
}