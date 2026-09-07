class Solution {
public:
    //unordered_set<uint64_t> tt{};
    vector<uint64_t> sol{};

    array<uint64_t, 8> ranks{};
    array<uint64_t, 8> files{};
    array<uint64_t, 64> left{};
    array<uint64_t, 64> right{};

    vector<uint64_t> board{};
    uint64_t pieces{};
    uint64_t mask{};

    Solution(){
        uint64_t ldiag = 0x8040201008040201ULL;
        uint64_t rdiag = 0x0102040810204080ULL;
        uint64_t msk;
        for (int i = 0; i < 8; i++){
            ranks[i] = (0xFFULL << (i << 3));
            files[i] = 0x0101010101010101ULL << i;

            msk = rdiag << (i << 3);
            while (msk){
                int p = countr_zero(msk);
                right[p] = rdiag << (i << 3);
                msk &= (msk - 1);
            }

            msk = rdiag >> (i << 3);
            while (msk){
                int p = countr_zero(msk);
                right[p] = rdiag >> (i << 3);
                msk &= (msk - 1);
            }

            msk = ldiag << (i << 3);
            while (msk){
                int p = countr_zero(msk);
                left[p] = ldiag << (i << 3);
                msk &= (msk - 1);
            }

            msk = ldiag >> (i << 3);
            while (msk){
                int p = countr_zero(msk);
                left[p] = ldiag >> (i << 3);
                msk &= (msk - 1);
            }
        }

        board.clear();
        board.push_back(0ULL);
        pieces = 0ULL;
    }

    uint64_t attacks(int sq){
        return (ranks[sq >> 3] | files[sq & 7] | 
            left[sq] | right[sq]) & mask;
    }

    void dfs(int n, int ply){
        if (n == 0){
            sol.push_back(pieces);
            return;
        }

        uint64_t xset = ~board[ply] & mask & ranks[ply];
        while (xset){
            int p = countr_zero(xset);

            board.push_back((board[ply] | attacks(p)) & mask);
            pieces ^= (1ULL << p);

            dfs(n - 1, ply + 1);

            board.pop_back();
            pieces ^= (1ULL << p);

            xset &= (xset - 1);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        //tt.clear();
        sol.clear();
        mask = 0;
        for (int i = 0; i < n; i++){
            mask |= ((1ULL << n) - 1) << (i << 3);
        }

        dfs(n, 0);

        vector<vector<string>> res{};
        vector<string> ps{};
        char lx[2] = {'.', 'Q'};

        for (auto bb : sol){
            ps.clear();
            for (int i = 0; i < n; i++){
                string ss = "";
                for (int j = 0; j < n; j++){
                    int k = (i << 3) + j;
                    bool is = (bb >> k) & 1;
                    ss += lx[is];                    
                }
                ps.push_back(ss);
            }
            res.push_back(ps);
        }
        cout << res.size();
        return res;
    }
};
