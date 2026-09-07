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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> nds{};
        nds.push({root, 0});

        vector<vector<int>> res{};
        vector<int> level{};
        int l = 0;

        while (!nds.empty()){
            pair<TreeNode*, int> pp = nds.front();
            nds.pop();
            if (pp.first == nullptr){ continue; }
            nds.push({pp.first->left, pp.second + 1});
            nds.push({pp.first->right, pp.second + 1});

            if (pp.second > l){
                res.push_back(level);
                level.clear();
                l++;
            }

            level.push_back(pp.first->val);
        }

        if (!level.empty()) { res.push_back(level); }

        return res;
    }
};
