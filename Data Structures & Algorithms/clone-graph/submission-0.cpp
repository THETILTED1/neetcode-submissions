/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){ return nullptr; }
        unordered_map<Node*, Node*> oldToNew{};
        stack<Node*> st{};

        oldToNew[node] = new Node(node->val);
        st.push(node);

        while (!st.empty()){
            Node* nptr = st.top();
            st.pop();

            for (Node* nn : nptr->neighbors){
                if (!oldToNew.contains(nn)){
                    oldToNew[nn] = new Node(nn->val);
                    st.push(nn);
                }

                oldToNew[nptr]->neighbors.push_back(oldToNew[nn]);
            }
        }

        return oldToNew[node];
    }
};
