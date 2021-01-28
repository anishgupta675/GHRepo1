import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[] finalPrices(int[] prices) {
        for(int i = 0; i < prices.length - 1; i++) {
            for(int j = i + 1; j < prices.length; j++) {
                if(prices[j] <= prices[i]) {
                    prices[i]-= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] prices = new int[n];
	for(int i = 0; i < n; i++)
		prices[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	prices = sol.finalPrices(prices);
	for(int i = 0; i < n; i++)
		System.out.print(prices[i] + " ");
    }
}