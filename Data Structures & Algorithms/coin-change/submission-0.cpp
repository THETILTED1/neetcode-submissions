class Solution {
public:
    void dfs(vector<int>& c, int amt, int& best, int prog, int l){
        if (amt <= 0){
            if (amt == 0){
                best = min(best, prog);
            }
            return;
        }
        if (l == c.size() - 1){
            int r = amt / c[l];
            if (amt % c[l] == 0){
                best = min(best, r + prog);
            }
            return;
        }
        int r = amt / c[l];
        if (best <= prog + r){
            return;
        }

        for (int i = l; i < c.size(); i++){
            dfs(c, amt - c[i], best, prog + 1, i);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0){ return 0; }

        int best = INT_MAX;
        sort(coins.begin(), coins.end(), greater<int>());

        dfs(coins, amount, best, 0, 0);

        if (best == INT_MAX) return -1;

        return best;        
    }
};
