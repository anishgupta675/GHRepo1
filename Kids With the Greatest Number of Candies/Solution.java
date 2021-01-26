import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = candies[0];
        List<Boolean> list = new ArrayList<Boolean>();
        for(int i = 0; i < candies.length; i++) {
            if(candies[i] > max) max = candies[i];
        }
        for(int i = 0; i < candies.length; i++) {
            if((candies[i] + extraCandies) >= max) list.add(i, true);
            else list.add(i, false);
        }
	return list;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] candies = new int[n];
	for(int i = 0; i < n; i++)
		candies[i] = Integer.parseInt(in.readLine());
	int extraCandies = Integer.parseInt(in.readLine());
	List<Boolean> list = new ArrayList<Boolean>();
	Solution sol = new Solution();
	list = sol.kidsWithCandies(candies, extraCandies);
	for(int i = 0; i < n; i++)
		System.out.print(list.get(i) + " ");
    }
}