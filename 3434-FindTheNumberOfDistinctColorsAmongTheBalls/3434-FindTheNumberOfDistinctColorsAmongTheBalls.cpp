// Last updated: 4/24/2026, 10:04:41 PM
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colorMap;  // Tracks the current color of each ball
        unordered_map<int, int> colorCount;  // Tracks the number of times a color appears
        vector<int> result;
        
        for (auto& query : queries) {
            int ball = query[0], color = query[1];

            // If the ball already has a color, decrease the count
            if (colorMap.find(ball) != colorMap.end()) {
                int oldColor = colorMap[ball];
                colorCount[oldColor]--;
                if (colorCount[oldColor] == 0) {
                    colorCount.erase(oldColor);  // Remove color if no ball has it
                }
            }

            // Assign new color to the ball
            colorMap[ball] = color;
            colorCount[color]++;

            // Store the current number of unique colors
            result.push_back(colorCount.size());
        }

        return result;
    }
};
