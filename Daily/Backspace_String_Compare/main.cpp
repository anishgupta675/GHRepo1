#include<bits/stdc++.h>

using namespace std;

class Solution {
    stack<int> backspaceCompare(string s) {
        int i = 0;
        stack<int> st;
        while(i < s.length()) {
            if(s[i] == '#') {
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
            i++;
        }
        return st;
    }
public:
    bool backspaceCompare(string s, string t) {
        int s_count = 0, t_count = 0;
        stack<int> st1 = backspaceCompare(s);
        stack<int> st2 = backspaceCompare(t);
        if(st1.size() != st2.size()) return false;
        while(!st1.empty() && !st2.empty()) {
            if(st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }
        return true;
    }
};

int main() {}