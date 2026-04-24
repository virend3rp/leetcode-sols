// Last updated: 4/24/2026, 10:10:44 PM
class Solution {
public:
int check(vector<int>& tops,vector<int>& bottoms, int target) {
    int rotationTop = 0, rotationBottom = 0;
    for (int i = 0; i < tops.size(); ++i) {
        // If target is not present in either half, it's impossible
        if (tops[i] != target && bottoms[i] != target) {
            return -1;
        }
        // Count rotations needed for top and bottom
        if (tops[i] != target) rotationTop++;
        if (bottoms[i] != target) rotationBottom++;
    }
    return min(rotationTop, rotationBottom);
}
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int result = check(tops, bottoms, tops[0]);
    if (result != -1) return result;
    if (tops[0] != bottoms[0]) {
        result = check(tops, bottoms, bottoms[0]);
    }
    return result;
    }
};