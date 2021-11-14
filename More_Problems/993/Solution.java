// Cousins in Binary Tree

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

class Store {
	TreeNode node;
	int height;
	Store(TreeNode node, int height) {
		this.node=node;
		this.height = height;
	}
}

public class Solution {
	public boolean isCousins(TreeNode root, int x, int y) {
		Store l = height(root, x, null, 0);
		Store r = height(root, y, null, 0);
		if(l!=null && r!= null){
			if(l.node != r.node && l.height==r.height) {
				return true;
			}
		}
		return false;
	}
	Store height(TreeNode root, int val,TreeNode parent, int level) {
		if(root ==null) {
			return null;
		}
		if(root.val==val) {
			Store s = new Store(parent,level);
			return s;
		}
		Store l = height(root.left, val, root, level+1);
		if(l==null) {
			return height(root.right, val, root, level+1);
		}
		return l;
	}
	public static void main(String[] args) throws IOException {}

}
