// Last updated: 4/24/2026, 10:07:20 PM
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);  // Adjacency list to store prerequisites
        vector<int> inDegree(n, 0);  // To track number of prerequisites for each course
        
        // Build the graph and calculate the in-degree
        for (const auto& relation : relations) {
            int prevCourse = relation[0] - 1;  // Convert to 0-indexed
            int nextCourse = relation[1] - 1;  // Convert to 0-indexed
            adj[prevCourse].push_back(nextCourse);
            inDegree[nextCourse]++;
        }
        
        queue<int> q;
        vector<int> courseCompletionTime(n, 0);  // To store the total time required to complete each course
        
        // Initialize the queue with courses that have no prerequisites (in-degree = 0)
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                courseCompletionTime[i] = time[i]; 
            }
        }
        
        int totalTime = 0;
        
        // Perform topological sorting using BFS
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            
            // Update the completion time of each dependent course
            for (int nextCourse : adj[course]) {
                inDegree[nextCourse]--;
                // Update the course completion time to account for prerequisites
                courseCompletionTime[nextCourse] = max(courseCompletionTime[nextCourse], courseCompletionTime[course] + time[nextCourse]);
                
                // If all prerequisites are done, add the course to the queue
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // The answer is the maximum time taken to finish any course
        for (int i = 0; i < n; ++i) {
            totalTime = max(totalTime, courseCompletionTime[i]);
        }
        
        return totalTime;
    }
};