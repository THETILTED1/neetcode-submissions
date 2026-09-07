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

TreeNode pool[2002];
int pid = 0;

class Solution {
public:
    int pi = 0;
    int ii = 0;

    TreeNode* build(vector<int>& po, vector<int>& io, int l){
        if (pi >= po.size()) return nullptr;
        if (io[ii] == l){
            ii++;
            return nullptr;
        }

        TreeNode* root = &pool[pid++];
        root->val = po[pi++];

        root->left = build(po, io, root->val);
        root->right = build(po, io, l);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pid = 0;
        return build(preorder, inorder, INT_MAX);
    }
};
