// Last updated: 4/24/2026, 10:11:37 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adjList[u].push_back({v, w});
        }

        // Queue to store {current node, cost so far, stops taken}
        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0}); // Start from source with 0 cost and 0 stops

        // Distance array to store minimum cost for each node
        vector<int> distance(n, 1e9);
        distance[src] = 0;

        while (!q.empty()) {
            auto [currNode, currCost, stops] = q.front();
            q.pop();

            // If we've already exceeded the allowed stops, skip further processing
            if (stops > k) continue;

            // Explore neighbors
            for (auto& [nextNode, weight] : adjList[currNode]) {
                int newCost = currCost + weight;

                // Only process the neighbor if we found a cheaper path
                // or we haven't visited the node with fewer stops
                if (newCost < distance[nextNode] && stops <= k) {
                    distance[nextNode] = newCost;
                    q.push({nextNode, newCost, stops + 1});
                }
            }
        }

        // If the destination is still at max value, return -1 (no valid path)
        return distance[dst] == 1e9 ? -1 : distance[dst];
    }
};
