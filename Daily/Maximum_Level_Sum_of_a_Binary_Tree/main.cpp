#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int cur_sum = 0;
    int max_sum = 0;
public:
    int maxLevelSum(TreeNode* root) {
        int lvl = 1, max_lvl = 1;
        queue<TreeNode *> q;
        max_sum = root->val;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            cur_sum = 0;
            while(sz) {
                TreeNode *cur_node = q.front();
                q.pop();
                cur_sum+= cur_node->val;
                if(cur_node->left) q.push(cur_node->left);
                if(cur_node->right) q.push(cur_node->right);
                sz--;
            }
            if(cur_sum > max_sum) {
                max_sum = cur_sum;
                max_lvl = lvl;
            }
            lvl++;
        }
        return max_lvl;
    }
};

int main() {}