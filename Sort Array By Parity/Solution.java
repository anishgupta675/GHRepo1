import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int index = 0;
        for(int i = 0; i < A.length; i++) {
            if(A[i] % 2 == 0) {
                int temp = A[index];
                A[index++] = A[i];
                A[i] = temp;
            }
        }
        return A;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[] A = new int[n];
	for(int i = 0 ; i < n; i++)
		A[i] = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	A = sol.sortArrayByParity(A);
	for(int i = 0; i < n; i++)
		System.out.print(A[i] + " ");
    }
}