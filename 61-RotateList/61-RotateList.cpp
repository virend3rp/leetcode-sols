// Last updated: 4/24/2026, 10:16:31 PM
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){return NULL;}
        if(k==0){return head;}
        ListNode* temp=head;
        int size=1;
        while(temp->next!=NULL){
            size++;
            temp=temp->next;
        }
        temp->next=head;
        k=k%size;
        k=size-k;
        ListNode* temp1=head;
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;

    }
};