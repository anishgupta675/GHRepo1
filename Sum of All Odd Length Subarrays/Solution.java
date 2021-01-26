import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {
        int result = 0;
        for(int i = 0; i < arr.length; i++) {
            int odd = ((arr.length - i) * (i + 1)) / 2;
            if(((arr.length - i) * (i + 1)) % 2 == 1)
                odd++;
            result+= odd * arr[i];
        }
        return result;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] arr = new int[n];
	for(int i = 0; i < n; i++)
		arr[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	System.out.println(sol.sumOddLengthSubarrays(arr));
    }
}