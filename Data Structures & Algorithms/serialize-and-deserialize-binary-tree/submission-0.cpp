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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string pr = "";
        stack<TreeNode*> st{};
        st.push(root);
        while (!st.empty()){
            TreeNode* r = st.top();
            st.pop();

            if (r){
                pr += to_string(r->val);

                st.push(r->right);
                st.push(r->left);
            } else {
                pr += "1001";
            }

            pr += ' ';
        }

        return pr;
    }

    TreeNode* build(stringstream& ss){
        int j;
        if (!(ss >> j) or j == 1001){
            return nullptr;
        }

        TreeNode* root = new TreeNode(j);
        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};
