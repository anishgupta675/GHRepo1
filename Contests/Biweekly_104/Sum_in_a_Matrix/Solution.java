import java.util.*;

class Solution {
    public int matrixSum(int[][] nums) {
        int sum = 0;
        // Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++) Arrays.sort(nums[i]);
        for(int j = 0; j < nums[0].length; j++) {
            int max_val = 0;
            for(int i = 0; i < nums.length; i++) max_val = Math.max(nums[i][j], max_val);
            sum+= max_val;
        }
        return sum;
    }
    public static void main(String[] args) throws Exception {}
}