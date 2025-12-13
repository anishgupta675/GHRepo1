#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkCode(string code) {
        if(!code.length()) return false;
        for(int i = 0; i < code.size(); i++) {
            if(!isalnum(code[i]) && code[i] != '_') return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> electronics;
        vector<string> grocery;
        vector<string> pharmacy;
        vector<string> restaurant;
        vector<string> res;
        for(int i = 0; i < code.size(); i++) {
            if(checkCode(code[i]) && isActive[i] == true) {
                if(businessLine[i] == "electronics") electronics.push_back(code[i]);
                if(businessLine[i] == "grocery") grocery.push_back(code[i]);
                if(businessLine[i] == "pharmacy") pharmacy.push_back(code[i]);
                if(businessLine[i] == "restaurant") restaurant.push_back(code[i]);
            }
        }
        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());
        res.insert(res.end(), electronics.begin(), electronics.end());
        res.insert(res.end(), grocery.begin(), grocery.end());
        res.insert(res.end(), pharmacy.begin(), pharmacy.end());
        res.insert(res.end(), restaurant.begin(), restaurant.end());
        return res;
    }
};

int main() {}