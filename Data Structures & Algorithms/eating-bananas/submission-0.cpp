class Solution {
public:
    int ceildiv(int a, int b){
        return a / b + !!(a % b);
    }
    int sim(vector<int>& p, int k){
        int s = 0;
        for (int v : p){
            s += ceildiv(v, k);
        }
        return s;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (int v : piles){
            r = max(r, v);
        }

        int bk;

        while (l <= r){
            int mid = (l + r) / 2;
            int ss = sim(piles, mid);
            if (ss <= h){
                bk = mid;
                r = mid - 1;
            }
            if (ss > h){ l = mid + 1; }
        }

        return bk;
    }
};
