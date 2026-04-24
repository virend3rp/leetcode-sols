// Last updated: 4/24/2026, 10:08:51 PM
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string minInteger(std::string num, int k) {
        int n = num.size();
        if (k <= 0) return num;
        
        for (int i = 0; i < n; i++) {
            // Find the smallest digit within the range of swaps
            int minIndex = i;
            for (int j = i + 1; j < n && (j - i) <= k; j++) {
                if (num[j] < num[minIndex]) {
                    minIndex = j;
                }
            }
            
            // If the smallest digit is already at position `i`, continue
            if (minIndex == i) continue;
            
            // Perform swaps to bring the smallest digit to position `i`
            char minChar = num[minIndex];
            for (int j = minIndex; j > i; j--) {
                num[j] = num[j - 1];
            }
            num[i] = minChar;
            
            // Decrease the number of swaps used
            k -= (minIndex - i);
            
            // If we run out of swaps, return the current string
            if (k <= 0) break;
        }
        
        return num;
    }
};
