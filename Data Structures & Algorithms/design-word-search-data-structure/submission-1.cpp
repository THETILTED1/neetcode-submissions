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

    bool traverse(string& word, int k, Node* root){
        if (!root)
            return false;
        if (k == word.size())
            return root->is;

        if (word[k] == '.'){
            for (int i = 0; i < 26; i++){
                Node*& next = root->children[i];
                if (next and traverse(word, k + 1, next))
                    return next;
            }
            return false;
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
        return traverse(word, 0, root);
    }
};
