class Solution {
public:
    unordered_map<string, vector<string>> adj{};

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        for (auto& e : tickets)
            adj[e[0]].push_back(e[1]);
        for (auto& [v, l] : adj)
            reverse(l.begin(), l.end());
        
        vector<string> res{};
        stack<string> st{};
        st.push("JFK");
        while (!st.empty()){
            string t = st.top();

            auto& l = adj[t];
            if (l.empty()){
                st.pop();
                res.push_back(t);
                continue;
            }
            
            string v = l.back();
            l.pop_back();
            st.push(v);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
