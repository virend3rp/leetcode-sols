// Last updated: 4/24/2026, 10:13:16 PM
class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

void addEdge(string u, string v, double rate) {
    graph[u].push_back({v, rate});
    graph[v].push_back({u, 1.0 / rate});
}
double bfsFind(string src, string dst) {
    if (!graph.count(src) || !graph.count(dst)) return -1;
    if (src == dst) return 1.0;

    unordered_map<string, bool> visited;
    queue<pair<string, double>> q;
    q.push({src, 1.0});
    visited[src] = true;

    while (!q.empty()) {
        auto [node, rate] = q.front();
        q.pop();
        for (auto [nbr, w] : graph[node]) {
            if (nbr == dst) return rate * w;
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push({nbr, rate * w});
            }
        }
    }
    return -1;
}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> final;
        for(int i=0;i<equations.size();i++){
            addEdge(equations[i][0],equations[i][1],values[i]);
        }
        for(int i=0;i<queries.size();i++){
            final.push_back(bfsFind(queries[i][0],queries[i][1]));
        }

        return final;
    }
};