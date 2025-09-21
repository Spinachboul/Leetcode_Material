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
int ans = INT_MIN;
private:
    int helper(TreeNode* root){
        if(!root) return 0;

        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        int pS = left + right + root->val;

        ans = max(ans, pS);
        return max(left, right) + root->val;

    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
      
    }
};