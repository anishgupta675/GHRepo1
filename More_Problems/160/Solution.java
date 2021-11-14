// Intersection of Two Linked Lists

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

/* Definition for singly-linked list. */
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> hs = new HashSet<ListNode>();
        while(headA != null) {
            hs.add(headA);
            headA = headA.next;
        }
        while(headB != null) {
            if(hs.contains(headB)) return headB;
            headB = headB.next;
        }
        return null;
    }
    public static void main(String[] args) throws IOException {}
}
