// Last updated: 4/24/2026, 10:16:09 PM
class Solution {
public:
    // Find indices of Nearest Smaller to Left
    vector<int> NearestSmallerLeft(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> final(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            final[i] = st.empty() ? -1 : st.top();  // Store index, not height
            st.push(i);
        }
        return final;
    }

    // Find indices of Nearest Smaller to Right
    vector<int> NearestSmallerRight(vector<int>& heights, int n) {
        stack<int> st;
        vector<int> final(n, n);  // Initialize to 'n' for elements with no smaller to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            final[i] = st.empty() ? n : st.top();  // Store index, not height
            st.push(i);
        }
        return final;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL = NearestSmallerLeft(heights, n);
        vector<int> NSR = NearestSmallerRight(heights, n);
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;  // Calculate the width of the rectangle
            int area = width * heights[i];   // Calculate the area
            maxArea = max(maxArea, area);    // Update max area
        }
        return maxArea;
    }
};
