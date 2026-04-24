// Last updated: 4/24/2026, 10:13:29 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Build the frequency map
        map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Use a min-heap to keep track of the top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        
        // Step 3: Push each unique element and its frequency into the min-heap
        for (auto& [num, freq] : freqMap) { // Iterate over the map directly
            minheap.push({freq, num});
            if (minheap.size() > k) {
                minheap.pop(); // Remove the least frequent element
            }
        }
        
        // Step 4: Extract elements from the heap into the result vector
        vector<int> final;
        while (!minheap.empty()) {
            final.push_back(minheap.top().second); // Get the number (second element of the pair)
            minheap.pop();
        }
        
        return final;
    }
};
