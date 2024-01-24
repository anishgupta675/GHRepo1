#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(right), right(right) {}
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
    int ans = 0;
    unordered_map<int, int> freq;
    void helper(TreeNode *root) {
        if(!root) return;
        freq[root->val]++;
        if(!root->left && !root->right) {
            int odd = 0;
            for(auto i : freq) {
                if(i.second % 2) odd++;
                if(odd >= 2) break;
            }
            if(odd <= 1) ans++;
        }
        helper(root->left);
        helper(root->right);
        freq[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return ans;
    }
};

int main() {}