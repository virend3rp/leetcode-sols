// Last updated: 4/24/2026, 10:13:56 PM
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }
        
        unsigned int uxor = static_cast<unsigned int>(xorAll);
        unsigned int rightmostSetBit = uxor & (-uxor);
        
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (static_cast<unsigned int>(num) & rightmostSetBit)
                num1 ^= num;
            else
                num2 ^= num;
        }
        return {num1, num2};
    }
};