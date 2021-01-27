import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length < 2) return 0;
        int max = (nums[0] - 1) * (nums[1] - 1);
        for(int i = 0; i < nums.length - 1; i++) {
            for(int j = i + 1; j < nums.length; j++)
                if(((nums[i] - 1) * (nums[j] - 1)) > max) max = (nums[i] - 1) * (nums[j] - 1);
        }
        return max;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] nums = new int[n];
	for(int i = 0; i < n; i++)
		nums[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	System.out.println(sol.maxProduct(nums));
    }
}