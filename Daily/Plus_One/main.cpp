#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(i == digits.size() - 1) {
                carry = (digits[i] + 1) / 10;
                digits[i] = (digits[i] + 1) % 10;
            } else {
                int temp = digits[i] + carry;
                carry = temp / 10;
                digits[i] = temp % 10;
            }
        }
        while(carry > 0) {
            digits.insert(digits.begin(), carry % 10);
            carry /= 10;
        }
        return digits;
    }
};

int main() {}