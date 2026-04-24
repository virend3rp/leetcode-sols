// Last updated: 4/24/2026, 10:09:36 PM
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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int k=0;
        while(temp!=NULL){
            temp=temp->next;
            k++;
        }
        int num=0;
        ListNode* temp1=head;
        while(k>0){
            num+=temp1->val<<(k-1);
            k--;
            temp1=temp1->next;
        }
        return num;
    }
};