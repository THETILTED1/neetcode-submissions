class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res{};
        unordered_map<int, int> discard{};
        priority_queue<int> pq{};

        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        res.push_back(pq.top());

        for (int r = k; r < nums.size(); r++){
            pq.push(nums[r]);

            discard[nums[r - k]]++;            

            while (discard[pq.top()] > 0){
                int e = pq.top();
                discard[e]--;
                pq.pop();
            }

            res.push_back(pq.top());
        }
    
        return res;        
    }
};
