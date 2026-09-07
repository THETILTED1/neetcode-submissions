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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* hh = nullptr;
        ListNode* np = nullptr;
        ListNode* prev = nullptr;
        int carry = 0;

        while (l1 or l2 or carry){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            ListNode* tmp = new ListNode((v1 + v2 + carry) % 10);
            carry = (v1 + v2 + carry) / 10;

            if (!hh){ hh = tmp; }

            prev = np;
            np = tmp;
            if (prev){ prev->next = np; }            

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return hh;
    }
};
