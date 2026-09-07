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
    bool between(int a, int b, int c){
        return (min(a, c) <= b) and (b <= max(a, c));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root) return nullptr;
        
        while (!between(p->val, root->val, q->val)){
            if (root->val <= min(p->val, q->val)){
                root = root->right;
            }
            if (root->val >= max(p->val, q->val)){
                root = root->left;
            }
        }

        return root;
        
    }
};
