// Last updated: 4/24/2026, 10:08:33 PM
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        auto compare = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; 
            }
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minheap(compare);
        
        for (auto& [num, freq] : freqMap) { 
            minheap.push({freq, num});
            }
        vector<int> final;
        while (!minheap.empty()) {
            for(int i=0;i<minheap.top().first;i++){
              final.push_back(minheap.top().second); 
            }
            minheap.pop();
        }
        return final;
    }
};