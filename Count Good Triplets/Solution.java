import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        if(arr.length < 3) return 0;
        int count = 0;
        for(int i = 0; i < arr.length - 2; i++) {
            for(int j = i + 1; j < arr.length - 1; j++) {
                if(Math.abs(arr[i] - arr[j]) <= a) {
                    for(int k = j + 1; k < arr.length; k++)
                        if(Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) count++;
                }
            }
        }
        return count;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] arr = new int[n];
	for(int i = 0; i < n; i++)
		arr[i] = Integer.parseInt(in.readLine());
	int a = Integer.parseInt(in.readLine()); int b = Integer.parseInt(in.readLine()); int c = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	System.out.println(sol.countGoodTriplets(arr, a, b, c));
    }
}