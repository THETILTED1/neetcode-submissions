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
    bool isValidBSTHelper(TreeNode* root, int l, int r){
        if (root == nullptr) return true;

        return root->val > l
            and root->val < r
            and isValidBSTHelper(root->left, l, root->val)
            and isValidBSTHelper(root->right, root->val, r);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, -INT_MAX, INT_MAX);
    }
};
