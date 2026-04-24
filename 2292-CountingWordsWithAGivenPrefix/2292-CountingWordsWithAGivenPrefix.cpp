// Last updated: 4/24/2026, 10:06:53 PM
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c = 0;
        int n = pref.length();
        for (const string& w : words) {
            if (w.size() >= n && w.compare(0, n, pref) == 0) {
                c++;
            }
        }
        return c;
    }
};