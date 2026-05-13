// Last updated: 5/14/2026, 12:04:25 AM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
4        vector<vector<pair<int, int>>> adjList(n);
5        for (auto& flight : flights) {
6            int u = flight[0];
7            int v = flight[1];
8            int w = flight[2];
9            adjList[u].push_back({v, w});
10        }
11        queue<tuple<int, int, int>> q;
12        q.push({src, 0, 0});
13        vector<int> distance(n, 1e9);
14        distance[src] = 0;
15
16        while (!q.empty()) {
17            auto [currNode, currCost, stops] = q.front();
18            q.pop();
19            if (stops > k) continue;
20            for (auto& [nextNode, weight] : adjList[currNode]) {
21                int newCost = currCost + weight;
22                if (newCost < distance[nextNode] && stops <= k) {
23                    distance[nextNode] = newCost;
24                    q.push({nextNode, newCost, stops + 1});
25                }
26            }
27        }
28
29        return distance[dst] == 1e9 ? -1 : distance[dst];
30    }
31};
32