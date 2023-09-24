#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = nums1.size();
        while(low <= high) {
            int nums1_mid = low + ((high - low) >> 1), nums2_mid = (((nums1.size() + nums2.size()) + 1) >> 1) - nums1_mid;
            int a1 = (!nums1_mid) ? INT_MIN : nums1[nums1_mid - 1], b1 = (!nums2_mid) ? INT_MIN : nums2[nums2_mid - 1], a2 = (nums1_mid == nums1.size()) ? INT_MAX : nums1[nums1_mid], b2 = (nums2_mid == nums2.size()) ? INT_MAX : nums2[nums2_mid];
            if(a1 <= b2 && a2 <= b1) {
                int l_max = max(a1, b1), r_min = max(a2, b2);
                double median = 0.0;
                if((nums1.size() + nums2.size()) % 2) median = l_max;
                else median = (l_max + r_min) / 2.0;
                return median;
            } else if(a2 < b1) low = nums1_mid + 1;
            else high = nums1_mid - 1;
        }
        return 0.0;
    }
};

int main() {}