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
    TreeNode* contructTree(int prestart, int preend, int poststart, vector<int> &preorder, vector<int> &postorder){
        // if there are no nodes to process, return NULL
        if(prestart > preend) return NULL;

        // base case: if only one node is left, return that node
        if(prestart==preend) return new TreeNode(preorder[prestart]);

        // the next element is the left child
        int leftRoot = preorder[prestart+1];
        
        // finding the number of nodes in the left subtree by searching in the postorder
        int numOfNodesInLeft = 1;
        while(postorder[poststart + numOfNodesInLeft -1] !=leftRoot){
            numOfNodesInLeft++;
        }
        
        // get the root element
        TreeNode* root = new TreeNode(preorder[prestart]);

        // recursively construct the left substree
        root->left = contructTree(prestart+1, prestart+numOfNodesInLeft, poststart , preorder, postorder);

        // recursively construct the right subtree
        root->right = contructTree(prestart + numOfNodesInLeft+1, preend, poststart + numOfNodesInLeft , preorder, postorder);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int numOfNodes = preorder.size();
        return contructTree(0, numOfNodes-1, 0,preorder, postorder);
        
    }
};