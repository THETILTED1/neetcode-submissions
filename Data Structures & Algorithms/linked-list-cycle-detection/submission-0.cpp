/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<uint64_t> ptrs{};

        while (head != nullptr){
            if (ptrs.contains(reinterpret_cast<uint64_t>(head->next))){
                return true;
            }
            ptrs.insert(reinterpret_cast<uint64_t>(head));
            head = head->next;
        }

        return false;
    }
};
