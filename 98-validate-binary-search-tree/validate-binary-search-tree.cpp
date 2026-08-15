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
public:
    bool is_true = true;

    bool isValidBST(TreeNode* root) {
        check(root, LLONG_MIN, LLONG_MAX);
        return is_true;
    }

    void check(TreeNode* root, long long low, long long high) {
        if (!root) return;

        if (root->val <= low || root->val >= high) {
            is_true = false;
            return;
        }

        check(root->left, low, root->val);
        check(root->right, root->val, high);
    }
};