// Last updated: 5/5/2026, 5:32:57 AM
1class Solution {
2public:
3    ListNode* rotateRight(ListNode* head, int k) {
4        if (!head || !head->next || k == 0) return head;
5
6        int len = 1;
7        ListNode* tail = head;
8        while (tail->next) { tail = tail->next; len++; }
9        k %= len;
10        if (k == 0) return head;
11        ListNode* newTail = head;
12        for (int i = 0; i < len - k - 1; i++) newTail = newTail->next;
13        tail->next = head; 
14        head = newTail->next;     
15        newTail->next = nullptr; 
16
17        return head;
18    }
19};