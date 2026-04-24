// Last updated: 4/24/2026, 10:03:41 PM
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](auto &a,auto &b){
            return a[2]<b[2];
        });
        vector<int> parent(n);
        iota(parent.begin(),parent.end(),0);
        function<int(int)> find=[&](int x){
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        };
        int components=n;
        int maxEdgeWeight=0;
        for(auto &e:edges){
            int u=find(e[0]),v=find(e[1]);
            if(u!=v){
                parent[u]=v;
                components--;
                maxEdgeWeight=max(maxEdgeWeight,e[2]);
                if(components==k) break;
            }
        }
       return components==k? maxEdgeWeight:0;
    }
};