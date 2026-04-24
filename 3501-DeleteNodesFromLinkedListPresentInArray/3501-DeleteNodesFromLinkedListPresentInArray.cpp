// Last updated: 4/24/2026, 10:04:31 PM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       set<int> st;
       for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
       }
       while(head!=nullptr && st.find(head->val) != st.end()){
            head=head->next;
       }
       ListNode* prev=new ListNode(-1);
       ListNode* curr=head;
       while(curr){
            if(st.find(curr->val) != st.end()){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
       }
    return head; 
    }
};