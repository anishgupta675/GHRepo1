#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr;
        int carry = 0;
        stack<int> st1;
        stack<int> st2;
        while(l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        while(!st1.empty() || !st2.empty() || carry) {
            int digit1 = (!st1.empty()) ? st1.top() : 0;
            int digit2 = (!st2.empty()) ? st2.top() : 0;
            int sum = digit1 + digit2 + carry;
            ListNode *node = new ListNode(sum % 10);
            node->next = res;
            res = node;
            carry = sum / 10;
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();
        }
        return res;
    }
};

int main() {}