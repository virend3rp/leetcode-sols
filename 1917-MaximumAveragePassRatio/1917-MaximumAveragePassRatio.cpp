// Last updated: 4/24/2026, 10:08:00 PM
class Solution {
public:
    struct Comp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            double gainA = (double)(a.first + 1) / (a.second + 1) - (double)a.first / a.second;
            double gainB = (double)(b.first + 1) / (b.second + 1) - (double)b.first / b.second;
            return gainA < gainB; 
        }
    };
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;

        for (auto &c : classes) {
            pq.push({c[0], c[1]});
        }
        while (extraStudents--) {
            auto [pass, total] = pq.top();
            pq.pop();
            pass++;
            total++;
            pq.push({pass, total});
        }
        double avg = 0.0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            avg += (double)pass / total;
        }
        
        return avg / classes.size();
    }
};
