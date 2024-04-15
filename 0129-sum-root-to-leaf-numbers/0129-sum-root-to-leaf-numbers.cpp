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
    int sumNumbers(TreeNode* root, int number) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return number * 10 + root->val;
        return sumNumbers(root->left, number * 10 + root->val) +
               sumNumbers(root->right, number * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) { return sumNumbers(root, 0); }
};