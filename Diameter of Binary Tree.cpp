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
    int maxi = INT_MIN;
    int traverse(TreeNode *root){
        if(root == NULL)    
            return 0;
        
        int left = traverse(root->left);
        int right = traverse(root->right);

        maxi = max(maxi, left+right);

        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int height = traverse(root);
        return maxi;
    }
};
