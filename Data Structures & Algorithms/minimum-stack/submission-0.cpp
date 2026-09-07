class MinStack {
public:
    stack<pair<int, int>> tr{};
    stack<int> elements{};

    MinStack() {
        
    }
    
    void push(int val) {
        if (tr.empty() or val < tr.top().second){
            tr.push({elements.size(), val});
        }
        elements.push(val);
    }
    
    void pop() {
        elements.pop();
        if (elements.size() == tr.top().first){
            tr.pop();
        }
    }
    
    int top() {
        return elements.top();
    }
    
    int getMin() {
        return tr.top().second;
    }
};
