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
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int &index, int i, int j){
        if(i > j)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index]);

        int split = find(inorder.begin(), inorder.end(), preorder[index]) - inorder.begin();
        index++;

        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size()-1);
    }
};
