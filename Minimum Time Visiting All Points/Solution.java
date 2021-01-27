import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int seconds = 0;
        if(points == null || points.length == 0) return seconds;
        int[] first = points[0];
        for(int i = 1; i < points.length; i++) {
            int[] next = points[i];
            int xMove = Math.abs(points[i][0] - first[0]);
            int yMove = Math.abs(points[i][1] - first[1]);
            seconds+= Math.min(xMove, yMove);
            seconds+= Math.abs(xMove - yMove);
            first = points[i];
        }
        return seconds;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int[][] points = new int[n][2];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++)
			points[i][j] = Integer.parseInt(in.readLine());
	}
	Solution sol = new Solution();
	System.out.println(sol.minTimeToVisitAllPoints(points));
    }
}