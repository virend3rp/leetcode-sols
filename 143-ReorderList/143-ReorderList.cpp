// Last updated: 4/24/2026, 10:15:17 PM
class Solution {
public:
    // Function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;  // Save the next node
            curr->next = prev;                // Reverse the current node's pointer
            prev = curr;                      // Move prev to the current node
            curr = nextNode;                  // Move to the next node
        }
        
        return prev;  // Return the new head of the reversed list
    }

    // Function to reorder the list
    void reorderList(ListNode* head) {
        if (!head || !head->next) return; // Handle empty or single-node list
        
        // Step 1: Find the middle of the list using the slow and fast pointer technique
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* secondHalf = reverseList(slow->next);
        slow->next = nullptr; // Break the list into two halves
        ListNode* firstHalf = head;
        while (secondHalf != nullptr) {
            // Save the next nodes
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            
            // Merge nodes
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            
            // Move pointers forward
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
