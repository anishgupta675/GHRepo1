#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string broken){
        bool b[26] = {0};
        int res = 0;

        for (char c : broken){
            b[c-97] = true;
        }

        stringstream ss(text);
        string w;
        while (ss >> w) {
            bool ok = true;
            for (char c : w) {
                if (b[c-97]){
                    ok = false;
                    break;
                }
            }
            if (ok){
                res = res + 1;
            }
        }

        return res;
    }
};

int main() {}