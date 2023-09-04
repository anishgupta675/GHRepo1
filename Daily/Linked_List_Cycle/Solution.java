import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution {

    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null) return false;
        ListNode slow_ptr = head, fast_ptr = head;
        while(fast_ptr != null && fast_ptr.next != null) {
            fast_ptr = fast_ptr.next.next;
            slow_ptr = slow_ptr.next;
            if(slow_ptr == fast_ptr) return true;
        }
        return false;
    }

    public static void main(String[] args) throws Exception {}
}