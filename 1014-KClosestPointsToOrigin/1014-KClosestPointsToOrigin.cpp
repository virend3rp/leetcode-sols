// Last updated: 4/24/2026, 10:10:53 PM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Custom comparator to compare points based on their distance from the origin
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            // Calculate the square of the distance for both points to avoid using sqrt()
            int d1 = a.first * a.first + a.second * a.second;
            int d2 = b.first * b.first + b.second * b.second;
            return d1 < d2;  // Max-heap: Compare distances in descending order
        };
        
        // Max-heap to store the k closest points
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        
        // Push points into the priority queue
        for (auto& point : points) { 
            pq.push({point[0], point[1]});
            if (pq.size() > k) {
                pq.pop();  // Remove the farthest point if the heap size exceeds k
            }
        }

        // Collect the result
        vector<vector<int>> final;
        while (!pq.empty()) {
            final.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        
        return final;
    }
};
