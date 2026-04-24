// Last updated: 4/24/2026, 10:12:54 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort the children's greed factors in non-decreasing order
        sort(s.begin(), s.end()); // sort the cookie sizes in non-decreasing order
        int i = 0; // pointer to the current child's greed factor
        int j = 0; // pointer to the current cookie size
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { // if the current cookie can satisfy the current child's greed factocontentChildren++;
                i++;
            }
            j++;
        }
        return i;
    }
};