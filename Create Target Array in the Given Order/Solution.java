import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> list = new ArrayList<Integer>(nums.length);
        for(int i = 0; i < nums.length; i++) {
            list.add(index[i], nums[i]);
        }
        for(int i = 0; i < list.size(); i++)
            nums[i] = list.get(i);
        return nums;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] nums = new int[n];
	for(int i = 0; i < n; i++)
		nums[i] = Integer.parseInt(in.readLine());
	int[] index = new int[n];
	for(int i = 0; i < n; i++)
		index[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	nums = sol.createTargetArray(nums, index);
	for(int i = 0; i < n; i++)
		System.out.print(nums[i] + " ");
    }
}