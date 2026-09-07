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
    ListNode* reverseList(ListNode* head) {
        ListNode* end = nullptr;
        ListNode* prev = nullptr;

        while (head != nullptr){
            end = new ListNode();
            end->val = head->val;
            end->next = prev;
            prev = end;
            head = head->next;
        }

        return end;
    }
};
