import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int findNumbers(int[] nums) {
        int c1 = 0;
        for(int i = 0; i < nums.length; i++) {
            int c2 = 0;
            for(int j = nums[i]; j > 0; j/= 10)
                c2++;
            if(c2 % 2 == 0) c1++;
        }
        return c1;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] nums = new int[n];
	for(int i = 0; i < n; i++)
		nums[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	System.out.println(sol.findNumbers(nums));
    }
}