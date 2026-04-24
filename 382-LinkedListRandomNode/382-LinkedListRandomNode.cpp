// Last updated: 4/24/2026, 10:13:21 PM
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
    int count = -1;
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* temp = head;
        if(count == -1){
            count = 0;
            while(temp){
                count++;
                temp = temp->next;
            }
        }
        temp = head;
        int index = rand() % count + 1;
        while(index > 1){
            temp = temp->next;
            index--;
        }
        return temp->val;
    }
};

// Karamjeet Sony