// Last updated: 4/24/2026, 10:11:47 PM
class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> freqmap;
        for (char c : s) {
            freqmap[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : freqmap) {
            pq.push({it.second, it.first});
        }
        string result = "";
        while (pq.size() >= 2) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            result += top1.second;
            result += top2.second;
            if (--top1.first > 0) pq.push(top1);
            if (--top2.first > 0) pq.push(top2);
        }
        if (!pq.empty()) {
            auto last = pq.top(); pq.pop();
            if (last.first > 1) {
                return ""; 
            }
            result += last.second;
        }
        return result;
    }
};
