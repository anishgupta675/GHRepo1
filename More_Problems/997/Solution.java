// Find the Town Judge

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] in_degree = new int[n];
        int[] out_degree = new int[n];
        for(int i = 0; i < trust.length; i++) {
            in_degree[trust[i][1] - 1]++;
            out_degree[trust[i][0] - 1]++;
        }
        for(int i = 0; i < n; i++)
            if(in_degree[i] == n - 1 && out_degree[i] == 0) return i + 1;
        return -1;
    }
    public static void main(String[] args) throws IOException {}
}
