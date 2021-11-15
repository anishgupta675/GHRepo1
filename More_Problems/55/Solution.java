// Jump Game

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public boolean canJump(int[] nums) {
        int goal = nums.length - 1;
        for(int i = nums.length - 1; i >= 0; i--)
            if(i + nums[i] >= goal) goal = i;
        return (goal == 0);
    }
    public static void main(String[] args) throws IOException {};
}
