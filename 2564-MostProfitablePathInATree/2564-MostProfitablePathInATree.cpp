// Last updated: 4/24/2026, 10:06:03 PM
class Solution {
public:
    pair<int,int> T;
    bool dfs(vector<vector<int>>&adj,vector<int>&time,int curnode,int pretime){
        time[curnode]=pretime;
        for(auto i:adj[curnode]){
            if(i==0){
                time[i]=pretime+1;
                return true;
            }
            if(time[i]==-1 && dfs(adj,time,i,pretime+1)){
                return true;
            }
        }
        time[curnode]=-1;
        return false;
    }
    int alicedfs(vector<vector<int>>&adj,vector<int>&time,vector<int>&amount,int curnode,int step,int par){
        int totalprofit=0;
        if(time[curnode]==step){
            totalprofit+=amount[curnode]/2;
        }
        else if(time[curnode]==-1 || step<time[curnode]){
            totalprofit+=amount[curnode];
        }
        // cout<<totalprofit<<"  "<<curnode<<endl;
        int mn=INT_MIN/2;
        for(auto i:adj[curnode]){
            if(i!=par){
                
                int k=alicedfs(adj,time,amount,i,step+1,curnode);
                mn=max(totalprofit+k,mn);
                // cout<<i<<" "<<k<<"  "<<mn<<"  "<<totalprofit<<endl;
            }
        }
        // cout<<mn<<endl;
        if(mn==INT_MIN/2){
            // cout<<amount[curnode]<<" "<<totalprofit<<"  "<<curnode<<endl;
            return totalprofit;
        }
        return mn;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>time(n,-1);
        dfs(adj,time,bob,0);
        int ans=alicedfs(adj,time,amount,0,0,-1);
        // return 0;
        return ans;
    }
};