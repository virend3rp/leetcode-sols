// Last updated: 4/24/2026, 10:17:07 PM
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* dummy = nullptr;
        int count = 0;
        
        // First, check if there are at least k nodes remaining
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If we have k nodes, then we reverse this group
        if (count == k) {
            curr = head;
            count = 0;
            
            // Reverse k nodes
            while (curr != nullptr && count < k) {
                dummy = curr->next;
                curr->next = prev;
                prev = curr;
                curr = dummy;
                count++;
            }
            
            // After reversing, head is the last node of the reversed group
            // We now recursively call reverseKGroup on the rest of the list
            if (dummy != nullptr) {
                head->next = reverseKGroup(dummy, k);
            }
            
            // prev is now the new head of the reversed group
            return prev;
        }
        
        // If we don't have enough nodes to reverse, return the original head
        return head;
    }
};