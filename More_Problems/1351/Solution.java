// Count Negative Numbers in a Sorted Matrix

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public int countNegatives(int[][] grid) {
        int r = grid.length, c = grid[0].length, i = r - 1, j = 0, count = 0;
        while(i >= 0 && j < c) {
            if(grid[i][j] < 0) {
                count+= c - j;
                i--;
            } else j++;
        }
        return count;
    }
    public static void main(String[] args) throws IOException {}
}
