import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxSum = 0;
        for(int[] account : accounts) {
            int amount = 0;
            for(int balance : account) {
                amount+= balance;
            }
            if(amount >= maxSum) maxSum = amount;
        }
        return maxSum;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int m = Integer.parseInt(in.readLine()); int n = Integer.parseInt(in.readLine()); int[][] accounts = new int[m][n];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			accounts[i][j] = Integer.parseInt(in.readLine());
	}
	Solution sol = new Solution();
	System.out.println(sol.maximumWealth(accounts));
    }
}