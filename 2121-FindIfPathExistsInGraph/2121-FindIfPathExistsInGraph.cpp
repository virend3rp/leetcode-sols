// Last updated: 4/24/2026, 10:07:33 PM
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int>q;
        if(n<2){
            if(source==destination){
                return true;
            }
        }
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n+1,-1);
        visited[source]=1;
        q.push(source);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto& neighbour:graph[curr]){
                if(visited[neighbour]==-1){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
                if (neighbour == destination) return true;
            }
        }
        return false;
    }
};