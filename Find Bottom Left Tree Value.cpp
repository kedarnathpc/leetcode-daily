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
    int ans = 0, level = -1;
    void solve(TreeNode *root, int curLevel){
        if(!root)
            return;
        
        if(curLevel > level){
            ans = root->val;
            level = curLevel;
        }

        solve(root->left, curLevel + 1);
        solve(root->right, curLevel + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        solve(root, 0);
        
        return ans;
    }
};
