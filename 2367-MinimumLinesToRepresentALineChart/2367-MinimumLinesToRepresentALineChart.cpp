// Last updated: 4/24/2026, 10:06:41 PM
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
    if (stockPrices.size() <= 1) return 0; // No lines needed for 0 or 1 point

    // Sort based on day values
    sort(stockPrices.begin(), stockPrices.end());

    int lines = 1; // At least one line is required
    long long prevDy = stockPrices[1][1] - stockPrices[0][1]; // y2 - y1
    long long prevDx = stockPrices[1][0] - stockPrices[0][0]; // x2 - x1

    for (size_t i = 2; i < stockPrices.size(); i++) {
        long long dy = stockPrices[i][1] - stockPrices[i - 1][1];
        long long dx = stockPrices[i][0] - stockPrices[i - 1][0];

        // Check if the current slope is different from the previous one
        if (dy * prevDx != dx * prevDy) { // Cross multiplication avoids floating-point errors
            lines++;
            prevDx = dx;
            prevDy = dy;
        }
    }
     return lines;
    }
};