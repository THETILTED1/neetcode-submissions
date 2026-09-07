class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp{};

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.contains(key) or mp[key].size() == 0){
            return "";
        }

        vector<pair<int, string>>& arr = mp[key];

        int l = 0;
        int r = arr.size() - 1;
        int mid;
        while (l < r){
            mid = l + (r - l + 1) / 2;
            if (arr[mid].first <= timestamp){ l = mid; }
            else { r = mid - 1; }
        }

        if (arr[l].first <= timestamp){ return arr[l].second; }
        return "";
    }
};
