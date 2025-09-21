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
    void solve(TreeNode* root, vector<vector<int>>& ans){
        if(root == NULL)return;

        queue<TreeNode*> q;
        q.push(root); // making the first level and also create a separator
        q.push(NULL);
        vector<int> temp;

        while(!q.empty()){
            TreeNode* tempVal = q.front();
            q.pop();

            if(tempVal == NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp.push_back(tempVal->val);
                if(tempVal->left) q.push(tempVal->left);
                if(tempVal->right) q.push(tempVal->right);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans);
        return ans;
        
    }
};