// Last updated: 4/24/2026, 10:10:42 PM
class Solution {
 public:
  int bitwiseComplement(int N) {
    int mask = 1;

    while (mask < N)
      mask = (mask << 1) + 1;

    return mask ^ N;
  }
};