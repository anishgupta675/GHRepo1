import java.util.*;

class Solution {
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = nums1.length;
        while(low <= high) {
            int nums1_mid = low + ((high - low) >> 1), nums2_mid = (((nums1.length + nums2.length) + 1) >> 1) - nums1_mid, a1 = (nums1_mid == 0) ? Integer.MIN_VALUE : nums1[nums1_mid - 1], b1 = (nums2_mid == 0) ? Integer.MIN_VALUE : nums2[nums2_mid - 1], a2 = (nums1_mid == nums1.length) ? Integer.MAX_VALUE : nums1[nums1_mid], b2 = (nums2_mid == nums2.length) ? Integer.MAX_VALUE : nums2[nums2_mid];
            if(a1 <= b2 && a2 <= b1) {
                int l_max = Math.max(a1, b1), r_min = Math.max(a2, b2);
                double median = 0.0;
                if((nums1.length + nums2.length) % 2 == 0) median = (l_max + r_min) / 2.0;
                else median = l_max;
                return median;
            } else if(a2 < b1) low = nums1_mid + 1;
            else high = nums1_mid - 1;
        }
        return 0.0;
    }

    public static void main(String[] args) throws Exception {}
}