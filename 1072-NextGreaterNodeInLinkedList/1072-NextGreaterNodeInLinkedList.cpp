// Last updated: 4/24/2026, 10:10:37 PM
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ll;
        while(head){
            ll.push_back(head->val);
            head=head->next;
        }
        stack<int>s;
        for(int i=0;i<ll.size();i++){
            while(!s.empty() && ll[i]>ll[s.top()]){
                ll[s.top()]=ll[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            ll[s.top()]=0;
            s.pop();
        }
        return ll;
    }
};