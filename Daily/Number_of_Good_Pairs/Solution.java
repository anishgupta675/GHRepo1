import java.util.*;

class Solution {

    public int numIdenticalPairs(int[] nums) {
        if(nums.length < 2) return 0;
        int res = 0;
        for(int i = 0; i < nums.length - 1; i++) for(int j = i + 1; j < nums.length; j++) if(nums[i] == nums[j]) res++;
        return res;
    }

    public static void main(String[] args) throws Exception {}
}