class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq{};
    int ki;

    KthLargest(int k, vector<int>& nums) {
        ki = k;
        for (int n : nums){
            add(n);
        }
    }
    
    int add(int val) {
        if (pq.size() < ki){
            pq.push(val);
            return pq.top();
        }

        if (val > pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};
