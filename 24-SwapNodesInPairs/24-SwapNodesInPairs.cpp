// Last updated: 4/24/2026, 10:17:08 PM
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        // Traverse the list and swap pairs of nodes
        while (curr->next && curr->next->next) {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            
            // Perform the swap
            first->next = second->next;
            second->next = first;
            curr->next = second;

            // Move to the next pair
            curr = first;
        }

        // Return the new head (dummy->next)
        return dummy->next;
    }
};
