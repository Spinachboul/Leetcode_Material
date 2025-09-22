/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        while(r){
            if(p->val > r->val && q->val > r-> val){
                r = r-> right;
            }
            else if(p->val < r->val && q->val < r-> val){
                r = r->left;
            }
            else return r;
        }
        return nullptr;

        
    }
};