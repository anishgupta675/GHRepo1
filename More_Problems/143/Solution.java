// Reorder List

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
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Solution {
    ListNode left = null;
    public void reorderListUtil(ListNode right) {
        if(right == null) return;
        reorderListUtil(right.next);
        if(left == null) return;
        if(left != right && left.next != right) {
            ListNode temp = left.next;
            left.next = right;
            right.next = temp;
            left = temp;
        } else {
            if(left.next == right) {
                left.next.next = null;
                left = null;
            } else {
                left.next = null;
                left = null;
            }
        }
    }
    public void reorderList(ListNode head) {
        if(head != null) {
            left = head;
            reorderListUtil(left);
        }
    }
    public static void main(String[] args) throws IOException {}
}
