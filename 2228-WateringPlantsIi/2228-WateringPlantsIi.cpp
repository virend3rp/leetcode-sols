// Last updated: 4/24/2026, 10:07:07 PM
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int left = 0;
        int right = plants.size() - 1;
        int refills = 0;
        int currentCapA = capacityA;
        int currentCapB = capacityB;
        
        while (left <= right) {
            // Case when both Alice and Bob reach the same plant
            if (left == right) {
                // Use the one with more water remaining
                int maxCap = max(currentCapA, currentCapB);
                if (maxCap < plants[left]) {
                    refills++;
                }
                break;
            }
            
            // Alice waters from left
            if (currentCapA < plants[left]) {
                refills++;
                currentCapA = capacityA;
            }
            currentCapA -= plants[left];
            left++;
            
            // Bob waters from right
            if (currentCapB < plants[right]) {
                refills++;
                currentCapB = capacityB;
            }
            currentCapB -= plants[right];
            right--;
        }
        
        return refills;
    }
};