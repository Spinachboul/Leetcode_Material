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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        long long res = 1;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()){
            long long cnt = q.size();
            long long start = q.front().second;
            long long end = q.back().second;

            res = max(res, end - start + 1);

            for(int i=0  ; i<cnt ; i++){
                pair<TreeNode* , long long > curr = q.front();
                long long index =curr.second - start;

                q.pop();

                if(curr.first->left != NULL){
                    q.push({curr.first->left, (long long) 2 * index + 1});
                }
                if(curr.first->right != NULL){
                    q.push({curr.first->right , (long long) 2 * index + 2});
                }
            }
        }
        return res;
    }
};