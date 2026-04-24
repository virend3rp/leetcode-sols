// Last updated: 4/24/2026, 10:11:50 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the adjacency list
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& time : times) {
            int u = time[0] - 1; // convert to 0-based index
            int v = time[1] - 1; // convert to 0-based index
            int w = time[2];
            adjList[u].push_back({v, w});
        }

        // Step 2: Distance array initialized to a large value
        vector<int> distance(n, 1e9);
        distance[k - 1] = 0; // Start from node k (0-based index)

        // Step 3: Priority queue to process nodes in increasing order of distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1}); // Start with node k, with distance 0

        // Step 4: Dijkstra's algorithm to find the shortest paths
        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            // If we find a longer path, skip it
            if (currDist > distance[currNode]) continue;

            // Explore neighbors
            for (auto& [nextNode, weight] : adjList[currNode]) {
                int newDist = currDist + weight;
                if (newDist < distance[nextNode]) {
                    distance[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }

        // Step 5: Get the maximum time taken to receive the signal
        int maxTime = *max_element(distance.begin(), distance.end());
        return maxTime == 1e9 ? -1 : maxTime;
    }
};
