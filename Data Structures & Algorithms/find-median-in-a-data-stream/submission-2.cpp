class MedianFinder {
public:
    priority_queue<int> lower{};
    priority_queue<int, vector<int>, greater<int>> upper{};

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lv = !lower.empty() ? lower.top() : -INT_MAX;
        int uv = !upper.empty() ? upper.top() : INT_MAX;

        if (num < uv){
            lower.push(num);
        } else {
            upper.push(num);
        }

        while (upper.size() > lower.size()){
            int v = upper.top();
            upper.pop();
            lower.push(v);
        }
        while (lower.size() > upper.size() + 1){
            int v = lower.top();
            lower.pop();
            upper.push(v);
        }
        
    }
    
    double findMedian() {
        int lv = !lower.empty() ? lower.top() : -INT_MAX;
        int uv = !upper.empty() ? upper.top() : INT_MAX;
        if (lower.size() == upper.size()){
            return (lv + uv) / 2.0;
        }
        return lv;
    }
};
