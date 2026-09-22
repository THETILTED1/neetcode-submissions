struct Node{
    array<Node*, 26> children{};
    bool is = false;
};

class PrefixTree {
public:
    Node* root;

    PrefixTree() {
        root = new Node;
    }

    Node* traverse(string& s){
        Node* curr = root;
        for (char c : s)
            if (!(curr = curr->children[c - 'a']))
                return nullptr;
        return curr;
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c : word){
            Node*& next = curr->children[c - 'a'];
            if (!next)
                next = new Node;
            curr = next;
        }
        curr->is = true;
    }
    
    bool search(string word) {
        Node* p = traverse(word);
        return p and p->is;
    }
    
    bool startsWith(string prefix) {
        return traverse(prefix);
    }
};
