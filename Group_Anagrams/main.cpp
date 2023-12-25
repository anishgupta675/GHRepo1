#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            umap[word].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto i : umap) res.push_back(i.second);
        return res;
    }
};

int main() {}