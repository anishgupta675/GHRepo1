import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int c = 0;
        for(int i = 0 ; i < nums.length; i++) {
            if(i % 2 == 0) c+= nums[i];
        }
        int[] arr = new int [c]; int k = 0;
        for(int i = 0; i < nums.length; i++) {
            if(i % 2 == 0) {
                for(int j = 0; j < nums[i]; j++)
                    arr[k++] = nums[i + 1];
                i++;
            }
        }
        return arr;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] nums = new int[n];
	for(int i = 0; i < n; i++)
		nums[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	int[] arr = sol.decompressRLElist(nums);
	for(int i = 0; i < arr.length; i++)
		System.out.print(arr[i] + " ");
    }
}