// Last updated: 4/24/2026, 10:04:00 PM
class Solution {
public:
    int maxDistance(string s, int k) {
        int hor = 0 , ver = 0, mxx = 0, j = 0;
        for(auto i : s) {
            hor += i == 'N' ? 1 : i == 'S' ? -1 : 0;
            ver += i == 'W' ? 1 : i == 'E' ? -1 : 0;
            // cout << min(j + 1 , abs(hor) + abs(ver) + 2 * k) << " " << j + 1 << endl;
            mxx = max(mxx, min(j + 1 , abs(hor) + abs(ver) + 2 * k));
            j++;
        }
        // mxx = max(mxx, min(abs(x) + abs(y) + 2 * k, ));

        return mxx;
    }
};