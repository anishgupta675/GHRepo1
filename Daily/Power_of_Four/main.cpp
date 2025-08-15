#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isInteger(float n) {
        return (!(n - floor(n)));
    }
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        if(!isInteger(n / 4.0f)) return false;
        return isPowerOfFour(n / 4);
    }
};

int main() {}