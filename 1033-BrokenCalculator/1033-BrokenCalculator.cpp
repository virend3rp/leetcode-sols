// Last updated: 4/24/2026, 10:10:50 PM
class Solution {
public:
int brokenCalc(int startValue, int target) {
    int operations = 0;
    while (target > startValue) {
        if (target % 2 == 0) {
            target /= 2; // If target is even, divide by 2
        } else {
            target += 1; // If target is odd, increment to make it even
        }
        operations++;
    }
    return operations + (startValue - target); // Remaining decrements
}
};