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
static const int fast_io = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();



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

        TreeNode* root = new TreeNode(po[pi++]);
        root->left = build(po, io, root->val);
        root->right = build(po, io, l);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(preorder, inorder, INT_MAX);
    }
};
