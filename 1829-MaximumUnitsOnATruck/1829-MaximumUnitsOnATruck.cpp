// Last updated: 4/24/2026, 10:08:18 PM
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1]; // descending by units per box
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units = 0;
        sort(boxTypes.begin(), boxTypes.end(), compare);
        for (auto& box : boxTypes) {
            int count = min(box[0], truckSize);
            units += count * box[1];
            truckSize -= count;
            if (truckSize == 0) break;
        }

        return units;
    }
};
