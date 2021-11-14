// Container With Most Water

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public int maxArea(int[] height) {
        int first = 0, second = height.length - 1, max_val = 0;
        while(second - first > 0) {
            max_val = Math.max(max_val, Math.min(height[first], height[second]) * (second - first));
            if(height[first] >= height[second]) second--;
            else first++;
        }
        return max_val;
    }
    public static void main(String[] args) throws IOException {}
}
