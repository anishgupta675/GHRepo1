import java.util.*;

class Solution {

    private int uniquePaths(int[][] dp, int m, int n) {
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0) return 1;
        if(dp[m][n] != 0) return dp[m][n];
        dp[m][n] = uniquePaths(dp, m, n - 1) + uniquePaths(dp, m - 1, n);
        return dp[m][n];
    }

    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        return uniquePaths(dp, m - 1, n - 1);
    }

    public static void main(String[] args) throws Exception {}
}