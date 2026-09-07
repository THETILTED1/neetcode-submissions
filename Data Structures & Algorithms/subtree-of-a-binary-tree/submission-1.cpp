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
    void serialize(TreeNode* root, vector<int>& v){
        if (!root){
            v.push_back(10001); 
            return;
        } 
        v.push_back(root->val);
        serialize(root->left, v);
        serialize(root->right, v);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> vr{};
        serialize(root, vr);
        
        vector<int> vs{};
        serialize(subRoot, vs);

        for (int i = 0; i < vr.size() - vs.size() + 1; i++){
            int j = 0;
            bool f = true;
            for (; j < vs.size(); j++){
                if (vr[i + j] != vs[j]){
                    f = false;
                    break;
                }
            }
            if (f){ return true; }
            //i += j;
        }

        return false;
    }
};
