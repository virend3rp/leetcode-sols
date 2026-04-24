// Last updated: 4/24/2026, 10:06:27 PM
class Solution {
public:
int minimumRecolors(string blocks, int k) {
    int whites = 0, minOps = INT_MAX;
    for (int i = 0; i < k; i++)
        if (blocks[i] == 'W') whites++;
    minOps = whites;
    for (int i = k; i < blocks.size(); i++) {
        if (blocks[i] == 'W') whites++;
        if (blocks[i - k] == 'W') whites--;
        minOps = min(minOps, whites);
    }
    return minOps;
}
};