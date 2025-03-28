#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) colors.push_back(colors[i]);
        int result = 0, left = 0, right = 1;
        while (right < colors.size()) {
            if (colors[right] == colors[right - 1]) {
                left = right;
                right++;
                continue;
            }
            right++;
            if (right - left < k) continue;
            result++;
            left++;
        }
        return result;
    }
};

int main() {}
