// Last updated: 4/24/2026, 10:14:08 PM
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
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

    }
    ListNode* Reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;;
        }
        return prev; 
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        if(head->next->next==NULL){
            if(head->val!=head->next->val){
                return false;
            }
        }
        ListNode* m=middle(head);
        ListNode* temp=m->next;
        m->next=Reverse(temp);

        ListNode* head1=head;
        ListNode* head2=m->next;
        while(head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        temp=m->next;
        m->next=Reverse(temp);
        return true;
    }
};