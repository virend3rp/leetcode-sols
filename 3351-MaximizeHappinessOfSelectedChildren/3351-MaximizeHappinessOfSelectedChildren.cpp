// Last updated: 4/24/2026, 10:04:53 PM
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort happiness values in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long result = 0;
        
        // Select k employees with highest happiness
        for (int i = 0; i < k; i++) {
            // Calculate happiness after decrement
            int currentHappiness = happiness[i] - i;
            
            // If happiness becomes negative, no need to continue
            if (currentHappiness <= 0) break;
            
            // Add to total happiness
            result += currentHappiness;
        }
        
        return result;
    }
};