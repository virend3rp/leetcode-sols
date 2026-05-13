// Last updated: 5/13/2026, 11:17:14 PM
1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4
5        vector<vector<int>> graph(numCourses);
6
7        for (auto& p : prerequisites) {
8            int course = p[0];
9            int prereq = p[1];
10
11            graph[prereq].push_back(course);
12        }
13        vector<int> state(numCourses, 0);
14
15        function<bool(int)> dfs = [&](int node) {
16            if (state[node] == 1)
17                return false;
18            if (state[node] == 2)
19                return true;
20            state[node] = 1;
21            for (int neighbor : graph[node]) {
22                if (!dfs(neighbor))
23                    return false;
24            }
25            state[node] = 2;
26
27            return true;
28        };
29        for (int i = 0; i < numCourses; i++) {
30            if (!dfs(i))
31                return false;
32        }
33
34        return true;
35    }
36};