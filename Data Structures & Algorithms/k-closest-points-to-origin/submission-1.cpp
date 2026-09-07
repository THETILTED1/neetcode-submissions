class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Quickselect partitions the array in O(N) time
        std::nth_element(points.begin(), points.begin() + k, points.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            }
        );
        
        // The first k elements are now the closest ones. 
        // We just return a copy of that slice.
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
