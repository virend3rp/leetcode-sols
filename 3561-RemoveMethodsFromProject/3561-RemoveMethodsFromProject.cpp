// Last updated: 4/24/2026, 10:04:24 PM
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<int> invoking(n, 0); 
        vector<bool> sus(n, false); 
    
        for (const auto& invocation : invocations) {
            graph[invocation[0]].push_back(invocation[1]);
            invoking[invocation[1]]++;
        }
        marksusMethods(graph, sus, k);
        for (int i = 0; i < n; ++i) {
            if (!sus[i]) { 
                for (int neighbor : graph[i]) {
                    if (sus[neighbor]) {
                    
                        vector<int> result;
                        for (int j = 0; j < n; ++j) {
                            result.push_back(j);
                        }
                        return result;
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!sus[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }

    void marksusMethods(vector<vector<int>>& graph, vector<bool>& sus, int k) {
        stack<int> s;
        s.push(k);
        sus[k] = true;
        
        while (!s.empty()) {
            int method = s.top();
            s.pop();
            
            for (int neighbor : graph[method]) {
                if (!sus[neighbor]) {
                    sus[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }
};