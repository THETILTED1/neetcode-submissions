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
    void inorder(TreeNode* root, int k, int& l, int& v){
        if (!root){ return; }
        inorder(root->left, k, l, v);
        if (k == l){ return; }
        l++;
        if (k == l){ v = root->val; return; }
        inorder(root->right, k, l, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        int l = 0;
        int v = -1;
        inorder(root, k, l, v);
        return v;        
    }
};
