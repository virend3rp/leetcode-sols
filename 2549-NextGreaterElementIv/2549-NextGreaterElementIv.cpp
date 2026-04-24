// Last updated: 4/24/2026, 10:06:09 PM
class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n, -1); // Result array

        stack<pair<int, bool>> st; // {index, has_seen_first_greater}

        for (int i = 0; i < n; ++i) {
            stack<pair<int, bool>> temp;

            // Find elements in the stack smaller than current
            while (!st.empty() && nums[st.top().first] < nums[i]) {
                temp.push(st.top());
                st.pop();
            }

            // Current index starts fresh, looking for its first greater
            st.push({i, true});

            // Process elements in reverse (to maintain order)
            while (!temp.empty()) {
                auto [idx, is_first] = temp.top();
                temp.pop();

                if (is_first) {
                    st.push({idx, false});  // Mark that it has seen its first greater
                } else {
                    nge[idx] = nums[i];     // Found second greater
                }
            }
        }

        return nge;
    }

};