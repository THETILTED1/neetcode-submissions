class Solution {
public:
    bool catches(pair<int, int> a, pair<int, int> b, int t){
        return (t - a.first) * b.second <= (t - b.first) * a.second;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, int>> cars{};
        for (int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        int r = 1;
        int lead = n - 1;
        
        for (int i = n - 2; i >= 0; i--){
            if (!catches(cars[i], cars[lead], target)){
                lead = i;
                r++;
            }
        }

        return r;        
    }
};
