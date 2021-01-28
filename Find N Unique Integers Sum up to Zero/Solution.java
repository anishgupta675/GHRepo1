import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[] sumZero(int n) {
        int[] arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i * 2 - n + 1;
        return arr;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine());
	int[] arr = new int[n];
	Solution sol = new Solution();
	arr = sol.sumZero(n);
	for(int i = 0; i < n; i++)
		System.out.print(arr[i] + " ");
    }
}