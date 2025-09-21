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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            if(!st2.empty() && st2.top() == root){
                ans.push_back(root->val);
                st1.pop();
                st2.pop();
            }
            else{
                st2.push(root);
                if(root->right){
                    st1.push(root->right);
                }
                if(root->left){
                    st1.push(root->left);
                }
            }
        }
        return ans;
        
    }
};