class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> steps{};
        for (char t : tasks){
            steps[t - 'A']++;
        }
        sort(steps.begin(), steps.end(), greater<int>());

        int cts = 0;
        for (; cts < 26 and steps[cts] == steps[0]; cts++);

        int f = (steps[0] - 1) * (n + 1) + cts;
        return max(f, (int)tasks.size());
    }
};
