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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int cts = lists.size();
        lists.push_back(nullptr);
        while (cts > 1){
            for (int i = 0; i < cts; i += 2){
                ListNode* head = nullptr;
                ListNode* curr = nullptr;
                ListNode* prev = nullptr;

                ListNode* l[2] = {lists[i], lists[i + 1]}; 
                
                while (l[0] or l[1]){
                    int v[2];
                    v[0] = l[0] ? l[0]->val : INT_MAX;
                    v[1] = l[1] ? l[1]->val : INT_MAX;

                    bool t = v[0] > v[1];
                    prev = curr;
                    curr = l[t];
                    l[t] = l[t]->next;
                    if (!head) head = curr;
                    if (prev) prev->next = curr;                   
                }
                if (curr) curr->next = nullptr;

                lists[i / 2] = head; 
            }
            cts = (cts + 1) / 2;
            lists[cts] = nullptr;
        }
        return lists[0];
    }
};
