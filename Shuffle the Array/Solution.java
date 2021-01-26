import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[] shuffle(int[] nums, int n) {
        List<Integer> list = new ArrayList<Integer>(nums.length);
        int j = n;
        for(int i = 0; i < n; i++) {
            list.add(nums[i]);
            list.add(nums[j]);
            j++;
        }
        for(int i = 0; i < nums.length; i++) {
            nums[i] = list.get(i);
        }
        return nums;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] nums = new int[n * 2];
	for(int i = 0; i < (n * 2); i++)
		nums[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	nums = sol.shuffle(nums, n);
	for(int i = 0; i < (n * 2); i++)
		System.out.print(nums[i] + " ");
    }
}