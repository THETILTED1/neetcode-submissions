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
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, greater<pair<int, int>>> pq{};
        for (int i = 0; i < lists.size(); i++){
            if (lists[i]){
                pq.push({lists[i]->val, i});
            }
        }

        ListNode* head = nullptr;
        ListNode* prev;
        ListNode* curr = nullptr;

        while (!pq.empty()){
            prev = curr;
            curr = new ListNode();
            if (!head) head = curr;

            pair<int, int> a = pq.top();
            pq.pop();
            curr->val = a.first;
            lists[a.second] = lists[a.second]->next;
            if (lists[a.second]){
                pq.push({lists[a.second]->val, a.second});
            }

            if (prev) prev->next = curr;
        }

        return head;
    }
};
