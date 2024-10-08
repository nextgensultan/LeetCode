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
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = []() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
class Solution {
public:
    int result;
    int dfs(TreeNode* root)
    {
        // if(root==nullptr)
        //     return 0;
        int l = root->left==nullptr ? 0 : dfs(root->left);
        int r = root->right ==nullptr ? 0 : dfs(root->right);
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