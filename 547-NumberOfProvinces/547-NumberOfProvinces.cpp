// Last updated: 4/24/2026, 10:12:31 PM
class Solution {
public:
    void dfs(int node,vector <int> adj[],vector <int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> adj[V];
        for(int j=0;j<V;j++){
            for(int i=0;i<V;i++){
                if(isConnected[j][i]==1 && j!=i){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector <int> vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};