// Last updated: 4/24/2026, 10:13:27 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> final;
        for(int i=0;i<nums1.size();i++){
            s.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end()){
                final.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return final;     
    }
};