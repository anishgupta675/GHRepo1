import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length - 1, n = grid[0].length, p = 0, count = 0;
        while(m >= 0 && p < n) {
            if(grid[m][p] < 0) {
                m--;
                count+= n - p;
            } else p++;
        }
        return count;
    }
    // Driver Code
    static void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int[n1];
        int R[] = new int[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    static void sort(int arr[], int l, int r)
    {
        if (l < r) {
            int m = (l + r) / 2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int m = Integer.parseInt(in.readLine()); int n = Integer.parseInt(in.readLine()); int[][] grid = new int[m][n];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			grid[m][n] = Integer.parseInt(in.readLine());
	}
	Solution sol = new Solution();
	for(int i = 0; i < m; i++)
		sol.sort(grid[i], 0, grid[i].length - 1);
	System.out.println(sol.countNegatives(grid));
    }
}