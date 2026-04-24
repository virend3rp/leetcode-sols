// Last updated: 4/24/2026, 10:10:03 PM
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int>prev(m+1);
        for(int j=0;j<m+1;j++){
            prev[j] = 0;
        }
        for(int i=1;i<n+1;i++){
            vector<int>curr(m+1);
            curr[0] = 0;
            for(int j=1;j<m+1;j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1+ prev[j-1];
                }else{
                    curr[j] = max(curr[j-1],prev[j]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};