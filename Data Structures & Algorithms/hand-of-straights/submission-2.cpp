class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1)
            return true;
        if (hand.size() % groupSize)
            return false;

        sort(hand.begin(), hand.end());
        queue<pair<int, int>> q{};

        for (int i = 0; i < hand.size(); i++){
            if (q.empty() or q.front().first == hand[i]){
                q.emplace(hand[i], 1);
            } else {
                auto pp = q.front();
                if (hand[i] == pp.first + 1){
                    q.pop();
                    if (pp.second < groupSize - 1)
                        q.emplace(hand[i], pp.second + 1);
                } else {
                    return false;
                }
            }
        }

        return q.empty();
    }
};
