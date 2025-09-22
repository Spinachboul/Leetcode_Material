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
    bool isIdentical(TreeNode* r1, TreeNode* r2){
        if(r1==NULL && r2 ==  NULL) return true;
        if(r1==NULL || r2 == NULL || r1->val != r2->val) return false;

        if(!isIdentical(r1->left, r2->left) || (!isIdentical(r1->right , r2->right))) return false;
        return true;
    }


public:
    bool isSubtree(TreeNode* root, TreeNode* root1) {
        if(root==NULL){
            return false;
        }

        if(root->val == root1->val){
            if(isIdentical(root, root1)) return true;
        }

        return isSubtree(root->left, root1) || isSubtree(root->right, root1);







        
    }
};