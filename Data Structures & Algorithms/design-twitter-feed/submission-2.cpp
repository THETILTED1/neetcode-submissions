class RingBuffer{
    public:
        pair<int, int> data[10];
        int start = 0;
        int sz = 0;

        pair<int, int> get(int i){
            return data[(start + i) % 10];
        }

        pair<int, int> back(int i){
            return get(sz - i - 1);
        }

        void push(pair<int, int> p){
            data[(start + sz) % 10] = p;
            start += (sz == 10);
            start %= 10;
            sz += (sz < 10);
        }
};

class Twitter {
public:
    unordered_map<int, RingBuffer> history{};
    unordered_map<int, unordered_set<int>> follows{};
    int ts = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (!follows[userId].contains(userId)){
            follows[userId].insert(userId);
        }
        RingBuffer& rb = history[userId];
        rb.push({ts++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        if (!follows.contains(userId)){ return {}; }

        vector<int> res{};
        priority_queue<pair<int, int>> pq{};

        unordered_map<int, int> idx{};
        unordered_map<int, int> tu{};
        
        for (auto u : follows[userId]){
            if (idx[u] < history[u].sz){
                pair<int, int> pp = history[u].back(idx[u]++);
                pq.push(pp);
                tu[pp.second] = u;
            }
        }

        for (int i = 0; i < 10 and !pq.empty(); i++){
            int v = pq.top().second;
            pq.pop();
            res.push_back(v);

            int u = tu[v];
            tu.erase(v);

            if (idx[u] < history[u].sz){
                pair<int, int> pp = history[u].back(idx[u]++);
                pq.push(pp);
                tu[pp.second] = u;
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (!follows[followerId].contains(followeeId)){
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows[followerId].contains(followeeId)){
            follows[followerId].erase(followeeId);
        }
    }
};
