// Last updated: 4/24/2026, 10:05:05 PM
#include <vector>

class Solution {
public:
    std::vector<int> findPeaks(std::vector<int>& mountains) {
        std::vector<int> result;
        int n = mountains.size();
        if (n <= 1) {
            return result; // Return empty result if there's 0 or 1 mountain
        }
        binarySearch(mountains, 1, n - 2, result); // Start searching from index 1 to n-2
        return result;
    }

private:
    void binarySearch(std::vector<int>& mountains, int start, int end, std::vector<int>& result) {
        if (start <= end) {
            int mid = start + (end - start) / 2;
            // Check if the mid is a peak
            if (mountains[mid] > mountains[mid - 1] && mountains[mid] > mountains[mid + 1]) {
                result.push_back(mid);
            }
            // Continue searching in both halves
            binarySearch(mountains, mid + 1, end, result);
            binarySearch(mountains, start, mid - 1, result);
        }
    }
};
