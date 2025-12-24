#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int res = 0, total_apples = 0;
        sort(capacity.begin(), capacity.end(), greater<>());
        for(int i = 0; i < apple.size(); i++) {
            total_apples += apple[i];
        }
        for(int i = 0; i < capacity.size(); i++) {
            if(total_apples <= 0) break;
            total_apples -= capacity[i];
            res++;
        }
        return res;
    }
};

int main() {}