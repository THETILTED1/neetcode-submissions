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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* o = head;
        ListNode* fast = head;
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }
        if (fast == nullptr){ // delete first element
            return head->next;
        }
        ListNode* prev = head;
        while (fast != nullptr){
            fast = fast->next;
            prev = head;
            head = head->next;
        }
        prev->next = prev->next->next;

        return o;
    }
};
