import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int diagonalSum(int[][] mat) {
        int sum = 0;
        for(int i = 0; i < mat.length; i++)
            sum+= mat[i][i];
        for(int i = 0; i < mat.length; i++)
            sum+= mat[i][(mat.length - 1) - i];
        if((mat.length - 1) % 2 == 0) sum-= mat[(mat.length - 1) / 2][(mat.length - 1) / 2];
        return sum;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[][] mat = new int[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			mat[i][j] = Integer.parseInt(in.readLine());
	}
	Solution sol = new Solution();
	System.out.println(sol.diagonalSum(mat));
    }
}