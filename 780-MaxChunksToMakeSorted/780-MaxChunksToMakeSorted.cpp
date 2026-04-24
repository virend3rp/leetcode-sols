// Last updated: 4/24/2026, 10:11:46 PM
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        int m = -1;
        for (int i = 0; i < n; ++i) {
            m = max(m, arr[i]);
            if (m == i) {
                ++res;
            }
        }
        return res;
    }
};
