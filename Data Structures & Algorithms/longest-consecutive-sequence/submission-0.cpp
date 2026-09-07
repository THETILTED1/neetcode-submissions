#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> byLow; // sequences indexed by lowest
        unordered_map<int, int> byHigh; // sequences by highest
        unordered_set<int> seen;

        int biggest = 0;

        for (int n : nums){
            if (seen.contains(n)) continue;
            else seen.insert(n);

            bool fromLow = byLow.contains(n + 1);
            bool fromHigh = byHigh.contains(n - 1);

            if (!fromLow) {
                if (!fromHigh) {
                    byLow.insert({n, 1});
                    byHigh.insert({n, 1});
                    if (1 > biggest){ biggest = 1; }
                } else {
                    int l = byHigh.at(n - 1);
                    byHigh.erase(n - 1);
                    byHigh.insert({n, l + 1});
                    byLow.at(n - l)++;
                    if (l + 1 > biggest){ biggest = l + 1; }
                }
            } else {
                if (!fromHigh){
                    int l = byLow.at(n + 1);
                    byLow.erase(n + 1);
                    byLow.insert({n, l + 1});
                    byHigh.at(n + l)++;
                    if (l + 1 > biggest){ biggest = l + 1; }
                } else { // merge
                    int l = byLow.at(n + 1);
                    int m = byHigh.at(n - 1);
                    byLow.erase(n + 1);
                    byHigh.erase(n - 1);
                    byLow.at(n - m) = l + m + 1;
                    byHigh.at(n + l) = l + m + 1;
                    if (l + m + 1 > biggest){ biggest = l + m + 1; }
                }
                
            }
        }

        return biggest;

    }
};
