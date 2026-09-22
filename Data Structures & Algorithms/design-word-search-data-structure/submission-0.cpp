struct Node{
    array<Node*, 26> children{};
    bool is = false;
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node;
    }

    Node* traverse(string& word, int k, Node* root){
        if (root == nullptr)
            return nullptr;
        if (k == word.size())
            return root;

        if (word[k] == '.'){
            for (char x = 'a'; x <= 'z'; x++){
                Node*& next = root->children[x - 'a'];
                Node* ptr;
                if (next and (ptr = traverse(word, k + 1, next)))
                    return ptr;
            }
            return nullptr;
        }
        Node*& next = root->children[word[k] - 'a'];
        return traverse(word, k + 1, next);
    }
    
    void addWord(string word) {
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
        Node* p = traverse(word, 0, root);
        return p and p->is;
    }
};
