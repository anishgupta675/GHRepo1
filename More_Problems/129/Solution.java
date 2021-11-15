// Sum Root to Leaf Numbers

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

/* Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
public class Solution {
    
    int total = 0; // Global variable which hold our sum;
    
    public int sumNumbers(TreeNode root) {
        total = 0;
        helper(root, 0); // helper functions holds the root i.e. 4 & leaf node which is intially 0
        return total;
    }
    
    void helper(TreeNode root, int sum){
        // Base Condition
        if(root == null) return;
        
        sum = sum * 10 + root.val;
        
        if(root.left == null && root.right == null){
            total += sum;
            return;
        }
        
        helper(root.left, sum);
        helper(root.right, sum);
    }

    public static void main(String[] args) throws IOException {}
}
