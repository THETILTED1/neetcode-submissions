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
    bool sameNode(TreeNode* p, TreeNode* q){
        return (p and q and p->val == q->val) or !(p or q);
    }
    bool dfs(TreeNode* p, TreeNode* q){
        if (!sameNode(p, q)){ return false; }
        if (!(p and q)){ return true; }
        bool l = dfs(p->left, q->left);
        if (!l){ return false; }
        return dfs(p->right, q->right);       
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};
