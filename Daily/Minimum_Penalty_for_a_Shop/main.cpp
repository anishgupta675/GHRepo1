#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int bestClosingTime(string customers) {
		vector<int> prefix_n(customers.length() + 1, 0);
		vector<int> postfix_y(customers.length() + 1, 0);
		for(int i = 1; i <= customers.length(); i++) {
			prefix_n[i] = prefix_n[i - 1];
			if(customers[i - 1] == 'N') prefix_n[i]++;
		}
		for(int i = customers.length() - 1; i >= 0; i--) {
			postfix_y[i] = postfix_y[i + 1];
			if(customers[i] == 'Y') postfix_y[i]++;
		}
		int min_penalty = INT_MIN, idx = 0;
		for(int i = 0; i <= customers.length(); i++) {
			int penalty = prefix_n[i] + postfix_y[i];
			if(penalty < min_penalty) {
				min_penalty = penalty;
				idx = i;
			}
		}
		return idx;
	}
};

int main() {}
