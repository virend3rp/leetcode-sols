// Last updated: 4/24/2026, 10:06:02 PM
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
// Function to reverse a linked list
ListNode *reverseNode(ListNode *head){
    ListNode *curr = head,*prev = NULL,*nextptr = NULL;
    while(curr){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
    head = reverseNode(head);
    // Step 2: Process the reversed list
    ListNode *curr = head,*prev = NULL;
    int max_to_far = 0;
    while(curr){
        if(curr->val < max_to_far){
            prev->next = curr->next;
        }
        else{
            max_to_far = curr->val;
            prev = curr;
        }
        curr = curr->next;
    }

    // Step 3: Reverse the list back to original order
    return reverseNode(head);
    }
};