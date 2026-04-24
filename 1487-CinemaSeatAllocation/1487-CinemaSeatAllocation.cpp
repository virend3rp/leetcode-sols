// Last updated: 4/24/2026, 10:09:15 PM
class Solution {
public:
    static int maxNumberOfFamilies(const int n, const vector<vector<int>>& reservedSeats) noexcept {
        unordered_map<int, int> res(reservedSeats.size() * 1.20);

        // Iterate through reserved seats and mark them in the hashmap
        for (const vector<int>& rs : reservedSeats) {
            res[rs[0]] |= 1 << (rs[1] - 1); // Set the bit for reserved seats
        }

        // Account for all the empty rows that can fit two four-person groups each.
        int ans = 2 * (n - res.size());

        for (auto [r, row] : res) {
            if (!(row & 0b0111111110)) {
                // We can fit two four-person groups.
                ans += 2;
            } else if (
                !(row & 0b0111100000) ||  // Check if the first block of 4 seats is free
                !(row & 0b0000011110) ||  // Check if the second block of 4 seats is free
                !(row & 0b0001111000)) {  // Check if the third block of 4 seats is free
                // We can fit one four-person group.
                ++ans;
            }
        }

        return ans;
    }
};
