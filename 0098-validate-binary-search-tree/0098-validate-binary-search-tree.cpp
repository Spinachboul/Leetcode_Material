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
private:
    bool isValid(TreeNode* node, long mn, long mx){
        if(!node) return true;
        if(!(node->val > mn && node->val < mx)) return false;

        return isValid(node->left, mn, node->val) && isValid(node->right, node->val, mx);

    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN ,LONG_MAX);
    

        
    }
};