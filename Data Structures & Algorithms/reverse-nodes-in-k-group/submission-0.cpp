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
    ListNode* reverse(int k, ListNode* head, bool& fail, 
            ListNode*& np){

        if (!head){ return nullptr; }
        ListNode* prev = nullptr;
        ListNode* hh = head;
        ListNode* rh;
        int cts = 0;
        while (cts < k and hh){
            if (cts == k - 1 or !hh->next){
                rh = hh;
                head->next = rh->next;
                np = head->next;
            }

            ListNode* tmp = hh->next;
            hh->next = prev;
            prev = hh;
            hh = tmp;
            cts++;
        }

        if (cts < k){ fail = true; }

        return rh;
    }

    ListNode* tryReverse(int k, ListNode* head){
        return nullptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool f = false;
        ListNode* lk;
        ListNode* hh = reverse(k, head, f, lk);

        if (f){
            reverse(k, hh, f, lk);
            return head;
        }

        ListNode* jg;
        if (lk) jg = reverseKGroup(lk, k);
        head->next = jg;
        return hh;
    }
};
