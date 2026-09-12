class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool unresolved = true;
        for (int i = digits.size() - 1; i >= 0 and unresolved; i--){
            digits[i]++;
            unresolved = digits[i] > 9;
            digits[i] = !unresolved * digits[i];
        }
        if (unresolved)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
