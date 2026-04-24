// Last updated: 4/24/2026, 10:14:05 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      node->val=node->next->val;
      node->next=node->next->next;
    }
};