// Last updated: 5/13/2026, 11:55:54 PM
1class Solution {
2public:
3
4    unordered_map<Node*, Node*> mp;
5
6    Node* cloneGraph(Node* node) {
7        if (node == NULL)
8            return NULL;
9        if (mp.count(node))
10            return mp[node];
11        Node* clone = new Node(node->val);
12        mp[node] = clone;
13        for (Node* neighbor : node->neighbors) {
14            clone->neighbors.push_back(cloneGraph(neighbor));
15        }
16
17        return clone;
18    }
19};