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
    TreeNode* helper(int& index, string &str, int depth){
        if(index >= str.size()) return nullptr;
        int dashCount = 0;
        // count the number of dashes
        while(index + dashCount < str.size() && str[index+dashCount] == '-'){
            dashCount++;
        }
        // if the number of dashes does not match the current depth, 
        // return -1
        if(depth != dashCount) return nullptr;

        index += dashCount;
        int val = 0;
        while(index < str.size()  && isdigit(str[index])){
            val = val * 10 + (str[index] - '0');
            index++;
        }
        TreeNode* node  = new TreeNode(val);
        // recursively build the left and the right subtrees
        node->left = helper(index, str, depth+1);
        node->right = helper(index, str, depth+1);
        return node;



    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root = new TreeNode(0);
        int index = 0;
        return helper(index, traversal , 0);
        
    }
};