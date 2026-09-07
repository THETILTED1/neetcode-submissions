/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr){ return nullptr; }

        unordered_map<Node*, Node*> otn{};

        Node* hh = head;
        while (hh){
            Node* tmp = new Node(hh->val);
            otn.insert({hh, tmp});
            hh = hh->next;
        }
        hh = head;
        while (hh){
            otn[hh]->next = otn[hh->next];
            otn[hh]->random = otn[hh->random];
            hh = hh->next;
        }

        return otn[head];
    }
};
