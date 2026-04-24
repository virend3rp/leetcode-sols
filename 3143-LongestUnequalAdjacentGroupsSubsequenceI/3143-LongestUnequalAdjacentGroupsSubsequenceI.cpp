// Last updated: 4/24/2026, 10:05:17 PM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> final;
        final.push_back(words[0]);
        int n=groups.size();
        for(int i=1;i<n;i++){
            if(groups[i]!=groups[i-1]){
                final.push_back(words[i]);
            }
        }
        return final;
    }
};