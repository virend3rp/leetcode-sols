// Last updated: 4/24/2026, 10:10:59 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> prev(n,0),curr(n,0);
        for(int j=0;j<n;j++){prev[j]=matrix[0][j];}
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int u=matrix[i][j]+prev[j];
                int ld=matrix[i][j];
                if(j-1>=0)ld+=prev[j-1];
                else ld=INT_MAX;
                int rd=matrix[i][j];
                if(j+1<n) rd+=prev[j+1];
                else rd=INT_MAX;
                int min1=min(ld,rd);
                curr[j]=min(u,min1);
            }
            prev=curr;
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,prev[j]);
        }
        return mini;
}
};