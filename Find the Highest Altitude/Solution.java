import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int largestAltitude(int[] gain) {
        int h = 0, max = 0;
        for(int i = 0; i < gain.length; i++) {
            h+= gain[i];
            if(h > max) max = h;
        }
        return max;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] gain = new int[n];
	for(int i = 0; i < n; i++)
		gain[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	System.out.println(sol.largestAltitude(gain));
    }
}