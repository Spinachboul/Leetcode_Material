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
    int heightCheck(TreeNode* root){
        if(!root) return 0;

        int left = heightCheck(root->left);
        int right = heightCheck(root->right);

        if(left == -1 || right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(left, right);

        
    }

    bool isBalanced(TreeNode* root){
        int ans = heightCheck(root);
        if(ans == -1) return false;
        return true;
    }
};