// Last updated: 4/24/2026, 10:06:31 PM
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
       unordered_map<int, int> mpp;
        
        // Process nums1
        for(int i = 0; i < nums1.size(); i++) {
            mpp[nums1[i][0]] = nums1[i][1];
        }
        
        // Process nums2
        for(int i = 0; i < nums2.size(); i++) {
            if(mpp.find(nums2[i][0]) != mpp.end()) {
                mpp[nums2[i][0]] += nums2[i][1];
            } else {
                mpp[nums2[i][0]] = nums2[i][1];
            }
        }
        
        // Convert map to result vector
        vector<vector<int>> result;
        for(auto& pair : mpp) {
            result.push_back({pair.first, pair.second});
        }
        
        // Sort the result by ID
        sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        return result;
    }
};