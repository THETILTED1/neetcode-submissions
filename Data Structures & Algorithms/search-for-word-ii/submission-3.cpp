struct Node{
    array<Node*, 26> e{};
    string* w = nullptr;
};

class Trie{
public:
    Node* root;

    Trie(){ root = new Node; }

    void insert(const string& word){
        Node* curr = root;
        for (char c : word){
            Node*& next = curr->e[c - 'a'];
            if (!next)
                next = new Node;
            curr = next;
        }
        curr->w = const_cast<string*>(&word);
    }

    bool contains(const string& word){
        Node* curr = root;
        for (char c : word)
            if (!(curr = curr->e[c - 'a']))
                return false;
        return curr->w;
    }
    
    void destroy(Node* root){
        for (int i = 0; i < 26; i++)
            if (root->e[i])
                destroy(root->e[i]);
        delete root;
    }
    ~Trie(){
        destroy(root);
    }
};

const array<pair<int, int>, 4> dir = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

class Solution {
public:
    bool bounds(int x, int y, vector<vector<char>>& g){
        return 0 <= x and x < g.size() and 0 <= y and y < g[0].size()
            and g[x][y];
    }

    void dfs(int x, int y, vector<vector<char>>& g, Node* n,
        vector<string>& res, int m, int k){
        
        char tmp = g[x][y];

        Node*& next = n->e[tmp - 'a'];
        if (!next)
            return;
        if (k == m)
            return;

        g[x][y] = 0;

        if (next->w){
            res.push_back(*next->w);
            next->w = nullptr;
        }
             
        for (const auto& d : dir){
            if (bounds(x + d.first, y + d.second, g))
                dfs(x + d.first, y + d.second, g, next, res, m, k + 1);
        }

        g[x][y] = tmp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        int m = 0;
        for (string& s : words){
            t.insert(s);
            m = max(m, static_cast<int>(s.size()));
        }

        vector<string> res{};

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(i, j, board, t.root, res, m, 0);

            
        return res;         
    }
};
