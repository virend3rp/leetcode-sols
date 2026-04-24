// Last updated: 4/24/2026, 10:05:10 PM
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int mp[105] = {0};
        int ans = INT_MAX;
        for(int i=0; i<edges.size(); i++)
            mp[edges[i][1]]++;

        for(int i=0; i<n; i++)
            if(mp[i]==0 && ans==INT_MAX) ans=i;
            else if(mp[i]==0) return -1;

        return ans;
    }
};