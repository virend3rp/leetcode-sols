// Last updated: 4/24/2026, 10:14:37 PM
class Solution {
public:
    unordered_set<int> freq; // To track seen numbers
    
    int squaresumofdigits(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10; // Extract the last digit
            sum += digit * digit; // Add the square of the digit
            n /= 10; // Remove the last digit
        }
        return sum;
    }
    
    bool isHappy(int n) {
        if (n == 1) {
            return true; // If we reach 1, it's a happy number
        }
        if (freq.find(n) != freq.end()) { 
            return false; // Cycle detected, not a happy number
        }
        freq.insert(n); // Mark current number as seen
        
        // Recursive call with the sum of the squares of the digits
        return isHappy(squaresumofdigits(n));
    }
};