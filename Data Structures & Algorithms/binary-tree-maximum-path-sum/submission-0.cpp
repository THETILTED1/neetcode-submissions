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
    void dfs(TreeNode* root,
        unordered_map<TreeNode*, int>& sc, // best as top
        int& mm){

        if (!root) return;

        int& ts = sc[root]; // best score for root as top

        dfs(root->left, sc, mm);
        int l = sc[root->left]; // left

        dfs(root->right, sc, mm);
        int r = sc[root->right]; // right
        int b = max(l, r); // best path down

        ts = max(b + root->val, root->val); 
        // take path down or don't

        int x = root->val + max(l, 0) + max(r, 0); 
        // possibly take both paths down
        mm = max(x, mm); // record global max
    }

    int maxPathSum(TreeNode* root) {
        unordered_map<TreeNode*, int> scores{};
        scores[nullptr] = -30000 * 1000;
        int global = INT_MIN;

        dfs(root, scores, global);

        return global;
    }
};
