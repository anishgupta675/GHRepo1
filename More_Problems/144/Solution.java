// Binary Tree Preorder Traversal

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
    public void preorderTraversalUtil(TreeNode root, List<Integer> res) {
        if(root == null) return;
        res.add(root.val);
        preorderTraversalUtil(root.left, res);
        preorderTraversalUtil(root.right, res);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        preorderTraversalUtil(root, res);
        return res;
    }
    public static void main(String[] args) throws IOException {}
}
