// Last updated: 4/24/2026, 10:05:48 PM
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2, 0);
        int i = 0;
        while (n > 0){
            if (n & 1){
                res[i % 2]++;
            }
            n >>= 1;
            i++;
        }
        return res;
    }
};
