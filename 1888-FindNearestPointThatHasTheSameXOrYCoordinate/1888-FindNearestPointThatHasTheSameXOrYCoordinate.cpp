// Last updated: 4/24/2026, 10:08:08 PM
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int mn = INT_MAX;  // Initialize minimum distance to maximum integer
        int ans = -1;  // Initialize the answer as -1 (in case no valid point is found)
        
        // Iterate through each point
        for (int i = 0; i < n; i++) {
            // Check if the point is valid (either x or y coordinate matches)
            if (points[i][0] == x || points[i][1] == y) {
                // Calculate Manhattan distance
                int manhattan = abs(x - points[i][0]) + abs(y - points[i][1]);
                
                // If the current point is closer, update the answer
                if (manhattan < mn) {
                    mn = manhattan;
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};
