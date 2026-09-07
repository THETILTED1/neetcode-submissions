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
    ListNode* revList(ListNode* head){
        ListNode* prev = nullptr;
        while (head != nullptr){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr){ return; }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while (fast and fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (fast == head){ return; }

        prev->next = nullptr;

        ListNode* ln = revList(slow);
        ListNode* lnp;
        
        ListNode* original = head;

        while (original != nullptr){
            prev = original;
            original = head->next;
            lnp = ln->next;

            head->next = ln;
            if (original == nullptr){ continue; }
            ln->next = original;

            ln = lnp;
            head = original;
        }
    }
};
