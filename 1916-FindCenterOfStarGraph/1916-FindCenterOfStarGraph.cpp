// Last updated: 4/24/2026, 10:08:01 PM
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> centre(n+1,0);
        for(auto& edge:edges){
            centre[edge[0]]++;
            centre[edge[1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(centre[i]==n-1){
                return i;
            }
        }
    return 0;    
    }
};