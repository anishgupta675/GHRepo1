#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for(int i = 1; i <= n; i++) {
            if(i % m) num1+= i;
            else num2+= i;
        }
        return num1 - num2;
    }
};

int main() {
    int n, m;
    Solution sol;
    cin >> n >> m;
    cout << sol.differenceOfSums(n, m) << endl;
}