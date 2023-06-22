#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long aheadNotBuy, aheadBuy, curBuy, curNotBuy;
        aheadNotBuy = aheadBuy = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            curNotBuy = max(prices[i] - fee + aheadBuy, aheadNotBuy);
            curBuy = max(-prices[i] + aheadNotBuy, aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};

int main() {}