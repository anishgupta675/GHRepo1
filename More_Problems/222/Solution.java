// Count Complete Tree Nodes

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
    public int countNodes(TreeNode root) {
        
        if(root==null)
            return 0;
        int lef=0,rig=0;
        TreeNode tmp=root;
        while(tmp.left!=null) {
		
            tmp=tmp.left;
            lef++;
        }
        tmp=root;
        while(tmp.right!=null){
		
            tmp=tmp.right;
            rig++;
        }
        if(lef==rig)
            return 2*((int)Math.pow(2,lef)-1)+1;
        return countNodes(root.left)+countNodes(root.right)+1;
    }
    public static void main(String[] args) throws IOException {}
}
