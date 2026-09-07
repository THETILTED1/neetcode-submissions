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
    vector<int> rightSideView(TreeNode* root) {
        stack<pair<TreeNode*, int>> st{};
        st.push({root, 0});

        int lvl = 0;
        vector<int> res{};

        while (!st.empty()){
            auto tp = st.top();
            st.pop();
            if (!tp.first) continue;

            st.push({tp.first->left, tp.second + 1});
            st.push({tp.first->right, tp.second + 1});

            if (tp.second == lvl){
                lvl++;
                res.push_back(tp.first->val);
            }
        }

        return res;
    }
};
