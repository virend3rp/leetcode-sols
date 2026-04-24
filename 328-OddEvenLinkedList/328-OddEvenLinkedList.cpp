// Last updated: 4/24/2026, 10:13:36 PM
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* oddHead=new ListNode (-1);
        ListNode* evenHead=new ListNode(-1);
        ListNode* odd=oddHead;
        ListNode* even=evenHead;
        ListNode* temp=head;
        bool flag=true;
        while(temp!=NULL){
            if(flag){
                ListNode* curr=temp;
                odd->next=curr;
                odd=odd->next;
            }
            else{
                ListNode* curr=temp;
                even->next=curr;
                even=even->next;
            }
            flag = !flag;
            temp=temp->next;
        }
        if(even){
            odd->next=evenHead->next;
        }
        even->next=NULL;

        return oddHead->next;        
    }
};