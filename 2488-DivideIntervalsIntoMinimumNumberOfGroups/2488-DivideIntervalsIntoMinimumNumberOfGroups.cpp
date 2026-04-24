// Last updated: 4/24/2026, 10:06:19 PM
// Approach - 01 [ Set ]
class Solution {
public:
    int minGroups(vector<vector<int>>& inter) {
        int n = inter.size();
        int ans = 0;
        // Sort based on interval starting value
        sort(inter.begin(), inter.end());
        multiset<int> st;
        for(int i = 0; i < n; i++) {
            int l = inter[i][0];
            int r = inter[i][1];
            if(st.empty()) {
                st.insert(r);
            }
            else {
                if (l > *st.begin()) {
                    st.erase(st.begin());
                    st.insert(r);
                }
                else{
                    st.insert(r);
                }
                // Insert the current interval's end time
            }
        }
        // The size of the set gives the number of groups
        return st.size();
    }
};