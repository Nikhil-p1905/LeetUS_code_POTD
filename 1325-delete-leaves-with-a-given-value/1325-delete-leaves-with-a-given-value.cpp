class Solution {
public:
    TreeNode* solve(TreeNode* root,int target)
    {
        if(!root)
        {
            return NULL;
        }
        // if(!root->left && !root->right)
        // {
        //     if(root->val==target)
        //     {
        //         return NULL;
        //     }

        //     return root;
        // }

        root->left = solve(root->left,target);
        root->right = solve(root->right,target);

        if(!root->left && !root->right)
        {
            if(root->val==target)
                return NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root,target);
    }
};