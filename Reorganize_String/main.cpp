#include<bits/stdc++.h>

using namespace std;

string kStringGenerate(string str, int k) {
    string res = "";
    vector<int> freq(26, 0);
    for(int i = 0; i < str.length(); i++) freq[str[i] - 'a']++;
    string single_copy = "";
    for(int i = 0; i < freq.size(); i++) {
        if(freq[i]) {
            if(freq[i] % k) return "Not Possible";
            else for(int j = 0; j < freq[i] / k; j++) single_copy = char(i + 97);
        }
    }
    for(int i = 0; i < k; i++) res+= single_copy;
    return res;
}

int main() {}