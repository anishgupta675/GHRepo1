import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[] replaceElements(int[] arr) {
        if(arr.length == 1) return new int[] {-1};
        for(int i = 0; i < arr.length - 1; i++) {
            int max = arr[i + 1];
            for(int j = i + 1; j < arr.length; j++)
                if(arr[j] > max) max = arr[j];
            arr[i] = max;
        }
        arr[arr.length - 1] = -1;
        return arr;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] arr = new int[n];
	for(int i = 0; i < n; i++)
		arr[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	arr = sol.replaceElements(arr);
	for(int i = 0; i < arr.length; i++)
		System.out.print(arr[i] + " ");
    }
}