#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool sign = n < 0;
        double res = 1.0;
        n = abs(n);
        while(n > 0) {
            if(n & 1) res*= x;
            x*= x;
            n>>= 1;
        }
        return (sign) ? 1.0 / res : res;
    }
};

int main() {}