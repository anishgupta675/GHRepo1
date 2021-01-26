import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int numIdenticalPairs(int[] nums) {
        int c = 0;
        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++)
                if(nums[i] == nums[j]) c++;
        }
        return c;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] nums = new int[n];
	for(int i = 0; i < n; i++)
		nums[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	System.out.println(sol.numIdenticalPairs(nums));
    }
}