// Last updated: 4/24/2026, 10:17:10 PM
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
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=lists.size();
        for (auto list : lists) {
        while (list != nullptr) {
            pq.push(list->val);
            list = list->next;
        }
        }
        if (pq.empty()) return nullptr;
         ListNode* root = new ListNode(pq.top());
         pq.pop();
        ListNode* current = root;

    while (!pq.empty()) {
        current->next = new ListNode(pq.top());
        pq.pop();
        current = current->next;
    }

    return root;
    }
};