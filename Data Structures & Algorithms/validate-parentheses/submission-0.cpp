class Solution {
public:
    bool closes(char a, char b){
        return (a == '(' and b == ')')
            or (a == '[' and b == ']')
            or (a == '{' and b == '}');
    }
    bool isValid(string s) {
        stack<char> st{};
        st.push('#');

        for (char c : s){
            if (closes(st.top(), c)){
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.size() == 1;
    }
};
