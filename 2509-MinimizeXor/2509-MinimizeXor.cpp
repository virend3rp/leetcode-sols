// Last updated: 4/24/2026, 10:06:13 PM
class Solution {
public:
int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += (num & 1); // Increment count if the least significant bit is 1
        num >>= 1;         // Right shift the number by 1
    }
    return count;
}

int minimizeXor(int num1, int num2) {
    int set_bits = countSetBits(num2);

    int x = 0;
    for (int i = 31; i >= 0 && set_bits > 0; --i) {
        if (num1 & (1 << i)) { // Check if the bit is set in num1
            x |= (1 << i);    // Set the same bit in x
            --set_bits;
        }
    }
    
    // If there are still set bits remaining, set them in x starting from the LSB
    for (int i = 0; i < 32 && set_bits > 0; ++i) {
        if (!(x & (1 << i))) { // Check if the bit is not already set in x
            x |= (1 << i);    // Set the bit in x
            --set_bits;
        }
    }
    
    return x;
}

};