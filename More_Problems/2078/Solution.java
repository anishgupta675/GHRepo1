// Two Furthest Houses With Different Colors

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public int maxStart(int[] colors, int n) {
        for(int i = n - 1; i > 0; i--)
            if(colors[0] != colors[i]) return i;
        return -1;
    }
    public int maxEnd(int[] colors, int n) {
        for(int i = 0; i < n; i++)
            if(colors[n - 1] != colors[i]) return i;
        return -1;
    }
    public int maxDistance(int[] colors) {
        return Math.max(maxStart(colors, colors.length), (colors.length - 1) - maxEnd(colors, colors.length));
    }
    public static void main(String[] args) throws IOException {}
}
