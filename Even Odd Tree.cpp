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
    bool isEvenOddTree(TreeNode* root) {
        bool even = true;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int prev = even ? INT_MIN : INT_MAX;
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                q.pop();

                if(even and (node->val % 2 == 0 or node->val <= prev))
                    return false;
                if(!even and (node->val % 2 == 1 or node->val >= prev))
                    return false;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);

                prev = node->val;
            }
            even == true ? even = false : even = true;
        }

        return true;
    }
};
