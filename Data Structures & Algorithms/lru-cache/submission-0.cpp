struct Node{
    Node* prev = nullptr;
    Node* next = nullptr;
    int key;
    int val;
};

class LRUCache {
public:
    unordered_map<int, Node*> mp{};
    int cap;   
    int sz = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    LRUCache(int capacity) {
        cap = capacity;
    }

    void cycle(Node* nptr){
        if (nptr == head){ return; }

        Node* p = nptr->prev;
        Node* n = nptr->next;

        if (p) p->next = n;
        if (n) n->prev = p;

        if (nptr == tail and p) {
            tail = p;
        }

        if (head) head->prev = nptr;
        nptr->next = head;
        nptr->prev = nullptr;
        head = nptr;

        if (!tail) tail = head;
    }
    
    int get(int key){
        if (!mp.contains(key)) { return -1; }
        
        Node* nptr = mp[key];
        cycle(nptr);
        
        return nptr->val;  
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            Node* nptr = mp[key];
            nptr->val = value;
            cycle(nptr);
            return;
        }

        Node* tmp = new Node();
        tmp->key = key;
        tmp->val = value;
        
        mp[key] = tmp;
        
        cycle(tmp);
        sz++;
        
        if (sz > cap) {
            Node* to_delete = tail;
            mp.erase(to_delete->key);
            
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            
            delete to_delete;
            sz--;
        }
    }
};
