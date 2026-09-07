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
    int dfs(TreeNode* root, int& mm){

        if (!root) return 0;

        int ts = 0;

        int l = dfs(root->left, mm);
        int r = dfs(root->right, mm);
        int b = max(l, r); // best path down

        ts = max(b + root->val, root->val); 
        // take path down or don't

        int x = root->val + max(l, 0) + max(r, 0); 
        // possibly take both paths down
        mm = max(x, mm); // record global max

        return ts;
    }

    int maxPathSum(TreeNode* root) {
        int global = INT_MIN;
        dfs(root, global);
        return global;
    }
};
