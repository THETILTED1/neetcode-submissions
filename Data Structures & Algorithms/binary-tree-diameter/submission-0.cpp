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
    pair<int, int> diam(TreeNode* root){
        if (!root) return {0, 0};

        pair<int, int> l = diam(root->left);
        pair<int, int> r = diam(root->right);

        pair<int, int> a{};
        a.first = 1 + max(l.first, r.first);
        a.second = max(l.second, r.second);
        a.second = max(a.second, l.first + r.first);
        
        return a;        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diam(root).second;
    }
};
