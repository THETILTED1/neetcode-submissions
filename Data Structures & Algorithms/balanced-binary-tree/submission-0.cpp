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
    bool lock = false;
    bool bal = true;
    int dfs(TreeNode* root){
        if (!root or lock) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);

        if (l - r > 1 or r - l > 1){
            lock = true;
            bal = false;
            return 0;
        }

        return 1 + max(l, r);

    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return bal;
    }
};
