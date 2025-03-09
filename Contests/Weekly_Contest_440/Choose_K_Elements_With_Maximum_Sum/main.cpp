#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> nums;
        for(int i = 0; i < nums1.size(); i++) {
            vector<int> data;
            data.push_back(i);
            data.push_back(nums1[i]);
            data.push_back(nums2[i]);
            nums.push_back(data);
            data.clear();
        }
        auto comp = [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        };
        sort(nums.begin(), nums.end(), comp);
        int total = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<long long> res(nums.size());
        for(int i = 0; i < res.size(); i++) {
            if(pq.size() == k) {
                if(pq.top() < nums[i][2]) {
                    total -= pq.top();
                    pq.pop();
                    pq.push(nums[i][2]);
                    total += nums[i][2];
                }
            } else {
                pq.push(nums[i][2]);
                total += nums[i][2];
            }
            res[i] = total;
        }
        return res;
    }
};

int main() {}
