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
    int result;
    int dfs(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        result = max(root->val , result);
        result = max(root->val + l + r ,result);
        result = max(root->val + l,result);
        result = max(root->val + r , result);
        return max(0,max(l , r)) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        this->result = -INT_MAX;
        result = max(result ,dfs(root));
        return result;
    }
};