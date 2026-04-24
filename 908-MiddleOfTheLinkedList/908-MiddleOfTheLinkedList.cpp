// Last updated: 4/24/2026, 10:11:17 PM
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fastT=head;
        ListNode* slowT=head;
        while(fastT!=NULL && fastT->next!=NULL){
            fastT=fastT->next->next;
            slowT=slowT->next;
        }
        return slowT;
    }
};
