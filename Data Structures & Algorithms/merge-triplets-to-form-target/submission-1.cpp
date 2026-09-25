class Solution {
public:
    bool leq(vector<int>& a, vector<int>& b){
        bool res = true;
        for (int i = 0; i < 3; i++)
            res &= (a[i] <= b[i]);
        return res;
    }
    void merge(vector<int>& a, vector<int>& b){
        for (int i = 0; i < 3; i++)
            a[i] = max(a[i], b[i]);
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> tmp(3, 0);
        for (auto& t : triplets)
            if (leq(t, target))
                merge(tmp, t);
        
        return tmp == target;        
    }
};
