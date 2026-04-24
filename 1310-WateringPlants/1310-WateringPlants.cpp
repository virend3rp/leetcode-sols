// Last updated: 4/24/2026, 10:09:56 PM
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int currentCapacity = capacity;
        
        for(int i = 0; i < plants.size(); i++) {
            // Count step to current plant
            steps++;
            
            // Check if we have enough water for current plant
            if(currentCapacity >= plants[i]) {
                // Water the current plant
                currentCapacity -= plants[i];
            } else {
                // Go back to river (i steps back)
                // Then return to current plant (i steps forward)
                steps += 2 * i;
                
                // Refill and water the plant
                currentCapacity = capacity - plants[i];
            }
        }
        
        return steps;
    }
};