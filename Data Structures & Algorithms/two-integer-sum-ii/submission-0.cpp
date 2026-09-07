class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0, b = numbers.size() - 1;
        
        while (a < b){
            while (numbers[b] + numbers[a] > target
                    and b > a){
                b--;
            }
            if (numbers[a] + numbers[b] == target){
                break;
            }
            a++;
        }

        return {a + 1, b + 1};
    }
};
