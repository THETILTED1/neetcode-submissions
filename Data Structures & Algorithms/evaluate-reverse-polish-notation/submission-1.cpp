class Solution {
public:
    bool isOp(string c){
        if (c.size() > 1){ return false; }
        bool r = false;
        for (char o : {'+', '-', '*', '/'}){
            r |= (c[0] == o);
        }
        return r;
    }

    int eval(int a , int b, char o){
        switch (o){
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:   
                return 0;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> tk{};

        for (string t : tokens){
            if (isOp(t)){
                int a = tk.top(); 
                tk.pop();
                int b = tk.top();
                tk.pop();
                tk.push(eval(b, a, t[0]));
            } else {
                tk.push(stoi(t));
            }
        }

        return tk.top();
    }
};
