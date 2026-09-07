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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        if (ptr1 == nullptr and ptr2 == nullptr){
            return nullptr;
        }

        ListNode* head;
        ListNode* ret;
        ListNode* prev = nullptr;

        while (ptr1 != nullptr or ptr2 != nullptr){
            head = new ListNode();
            if (prev != nullptr){ 
                prev->next = head;
            } else {
                ret = head;
            }
            prev = head;

            int v1 = (ptr1 != nullptr) ? ptr1->val : INT_MAX;
            int v2 = (ptr2 != nullptr) ? ptr2->val : INT_MAX;
            int nv = min(v1, v2);
            head->val = nv;

            if (v1 == nv){
                ptr1 = ptr1->next;
            } else {
                ptr2 = ptr2->next;
            }
        }

        return ret;
    }
};
