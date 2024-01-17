#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> occurence;
        unordered_map<int, int> freq;
        for(int i = 0; i < arr.size(); i++) freq[arr[i]]++;
        for(auto i : freq) {
            if(occurence.find(i.second) != occurence.end()) return false;
            occurence.insert(i.second);
        }
        return true;
    }
};

int main() {}