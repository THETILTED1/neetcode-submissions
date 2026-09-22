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
    
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++){
            Node*& next = curr->children[word[i] - 'a'];
            if (!next)
                next = new Node;
            curr = next;
        }
        curr->is = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size() - 1; i++)
            if (!(curr = curr->children[word[i] - 'a']))
                return false;
        
        auto& p = curr->children[word.back() - 'a'];
        return p and p->is;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++)
            if (!(curr = curr->children[prefix[i] - 'a']))
                return false;
            
        return true;
    }
};
