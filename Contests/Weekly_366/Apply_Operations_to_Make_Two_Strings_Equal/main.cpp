#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mod=1000000007;
    long long minOperations(vector<int>& arr, int n, int k)
    {
        long long ans = 0;
        int barr[31];
        for(int i=0;i<31;i++)barr[i]=0;
        for (int i=0;i<n;i++) {
            int x=arr[i];
            int j = 0;

            while (x) {
                if (x & 1)
                    barr[j]++;
                x >>= 1;
                j++;
            }
        }
        
        for (int i = 0; i < k; i++) {
            long long sum = 0;
            for (int j = 0; j < 30; ++j) {
                if (barr[j] > 0) {
                    sum =(sum+ (long)pow(2, j));
                    barr[j]--;
                }
            }

            long long y=(sum%mod * sum%mod)%mod;
            ans=(ans%mod+y%mod)%mod;
        }
        return ans%mod;

    }
    int maxSum(vector<int>& nums, int k) {
        return minOperations(nums,nums.size(),k);
    }
};

int main() {
    int x;
    string s1, s2;
    Solution sol;
    getline(cin, s1);
    getline(cin, s2);
    cin >> x;
    cout << sol.minOperations(s1, s2, x) << endl;
}