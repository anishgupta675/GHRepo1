import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i = 0; i < A.length; i++) {
            for(int j = 0, k = A[i].length - 1; j <= k; j++, k--) {
                int temp = A[i][j];
                A[i][j] = A[i][k];
                A[i][k] = temp;
            }
            for(int j = 0; j < A[i].length; j++)
                A[i][j] = (A[i][j] == 0) ? 1 : 0;
        }
        return A;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[][] A = new int[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			A[i][j] = Integer.parseInt(in.readLine());
	}
	Solution sol = new Solution();
	A = sol.flipAndInvertImage(A);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			System.out.print(A[i][j] + " ");
	}
    }
}