// Last updated: 4/24/2026, 10:08:30 PM
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = list1;
        ListNode* afterB = list1;
        
        // Move prevA to the (a-1)th node
        for (int i = 0; i < a - 1; i++) {
            prevA = prevA->next;
        }

        // Move afterB to the (b+1)th node
        afterB = prevA->next;
        for (int i = 0; i < (b - a + 1); i++) {
            afterB = afterB->next;
        }

        // Connect (a-1)th node to the head of list2
        prevA->next = list2;

        // Traverse to the end of list2
        ListNode* tail = list2;
        while (tail->next) {
            tail = tail->next;
        }

        // Connect list2's tail to (b+1)th node
        tail->next = afterB;

        return list1;
    }
};
