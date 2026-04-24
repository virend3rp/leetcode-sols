// Last updated: 4/24/2026, 10:13:34 PM
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < tickets.size(); i++) {
            string from = tickets[i][0];
            string to = tickets[i][1];
            graph[from].push_back(to);
        }
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            sort(it->second.rbegin(), it->second.rend());
        }
        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const string& airport, unordered_map<string, vector<string>>& graph, vector<string>& itinerary) {
        while (!graph[airport].empty()) {
            // Get the last destination (smallest lexicographically)
            string next = graph[airport].back();
            graph[airport].pop_back();
            dfs(next, graph, itinerary); // Recursively visit the next airport
        }
        itinerary.push_back(airport); // Add airport to itinerary once done
    }
};
