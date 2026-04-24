// Last updated: 4/24/2026, 10:06:07 PM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (const string& q : queries) {
            int len = q.size();
            for (const string& d : dictionary) {
                int diff = 0;
                for (int k = 0; k < len; k++) {
                    if (q[k] != d[k] && ++diff > 2) break;
                }
                if (diff <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};