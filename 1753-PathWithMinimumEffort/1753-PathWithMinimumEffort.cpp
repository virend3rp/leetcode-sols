// Last updated: 4/24/2026, 10:08:32 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    distance[0][0] = 0;
    
    // Priority queue to store {effort, {x, y}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,  greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    
    // Direction vectors for moving up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        int maxDist = curr.first;
        int currX = curr.second.first;
        int currY = curr.second.second;
        
        // Check all 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            
            // Ensure within bounds
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                // Calculate effort for the new position
                int newEffort = max(maxDist, abs(heights[newX][newY] - heights[currX][currY]));
                
                // Update distance if a smaller effort is found
                if (newEffort < distance[newX][newY]) {
                    distance[newX][newY] = newEffort;
                    pq.push({newEffort, {newX, newY}});
                }
            }
        }
    }
    
    // Return the minimum effort to reach the bottom-right corner
    return distance[n-1][m-1];
    }
};