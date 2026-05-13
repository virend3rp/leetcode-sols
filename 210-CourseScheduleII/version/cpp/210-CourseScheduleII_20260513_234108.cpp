// Last updated: 5/13/2026, 11:41:08 PM
1class Solution {
2public:
3    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
4        vector<vector<int>> graph(numCourses);
5        vector<int> indegree(numCourses, 0);
6        for (auto& p : prerequisites) {
7
8            int course = p[0];
9            int prereq = p[1];
10
11            graph[prereq].push_back(course);
12
13            indegree[course]++;
14        }
15        queue<int> q;
16
17        for (int i = 0; i < numCourses; i++) {
18            if (indegree[i] == 0)
19                q.push(i);
20        }
21        vector<int> order;
22        while (!q.empty()) {
23
24            int node = q.front();
25            q.pop();
26
27            order.push_back(node);
28            for (int neighbor : graph[node]) {
29
30                indegree[neighbor]--;
31                if (indegree[neighbor] == 0) {
32                    q.push(neighbor);
33                }
34            }
35        }
36        if (order.size() != numCourses)
37            return {};
38
39        return order;
40    }
41};