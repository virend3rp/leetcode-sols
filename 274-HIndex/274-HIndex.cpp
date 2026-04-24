// Last updated: 4/24/2026, 10:13:51 PM
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend()); // Sort in descending order
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                h = i + 1; // The maximum number of papers with at least `h` citations
            } else {
                break; // Once the condition fails, we stop checking further
            }
        }
        return h;
    }
};
