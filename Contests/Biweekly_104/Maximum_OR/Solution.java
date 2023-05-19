import java.util.*;

class Solution {
    public long maximumOr(int[] nums, int k) {
        long res = 0, p = 1;
        long[] pre = new long[nums.length + 1];
        long[] suf = new long[nums.length + 1];
        pre[0] = 0;
        suf[nums.length] = 0;
        p = p << k;
        for(int i = 0; i < nums.length; i++) pre[i + 1] = pre[i] | nums[i];
        for(int i = nums.length - 1; i >= 0; i--) suf[i] = suf[i + 1] | nums[i];
        for(int i = 0; i < nums.length; i++) res = Math.max(res, pre[i] | (nums[i] * p) | suf[i + 1]);
        return res;
    }
    public static void main(String[] args) throws Exception {}
}