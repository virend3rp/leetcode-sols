// Last updated: 5/14/2026, 12:33:19 AM
1class Solution {
2public:
3    int minCostConnectPoints(vector<vector<int>>& points) {
4        int n = points.size();
5        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
6        vector<bool> visited(n, false);
7        pq.push({0, 0});
8        int totalCost = 0;
9        int edgesUsed = 0;
10        while (edgesUsed < n) {
11            auto [cost, node] = pq.top();
12            pq.pop();
13            if (visited[node])
14                continue;
15            visited[node] = true;
16
17            totalCost += cost;
18            edgesUsed++;
19            for (int next = 0; next < n; next++) {
20
21                if (!visited[next]) {
22
23                    int x1 = points[node][0];
24                    int y1 = points[node][1];
25
26                    int x2 = points[next][0];
27                    int y2 = points[next][1];
28
29                    int dist = abs(x1 - x2) + abs(y1 - y2);
30
31                    pq.push({dist, next});
32                }
33            }
34        }
35
36        return totalCost;
37    }
38};