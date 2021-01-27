import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        boolean[] oddRows = new boolean[n], oddColumns = new boolean[m];
        for(int[] i : indices) {
            oddRows[i[0]]^= true;
            oddColumns[i[1]]^= true;
        }
        int r = 0, c = 0;
        for(boolean i : oddRows)
            r+= i ? 1 : 0;
        for(boolean i : oddColumns)
            c+= i ? 1 : 0;
        return (n - r) * c + (m - c) * r;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int m = Integer.parseInt(in.readLine()); int l = Integer.parseInt(in.readLine()); int[][] indices = new int[l][2];
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < 2; j++)
			indices[i][j] = Integer.parseInt(in.readLine());
	}
	Solution sol = new Solution();
	System.out.println(sol.oddCells(n, m, indices));
    }
}