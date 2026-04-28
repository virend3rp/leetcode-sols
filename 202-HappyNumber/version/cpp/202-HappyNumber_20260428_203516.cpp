// Last updated: 4/28/2026, 8:35:16 PM
1class Solution {
2public:
3int squareSumOfDigits(int n) {
4    int sum = 0;
5    while (n > 0) {
6        int d = n % 10;
7        sum += d * d;
8        n /= 10;
9    }
10    return sum;
11}
12
13bool isHappy(int n) {
14    int slow = n, fast = n;
15    do {
16        slow = squareSumOfDigits(slow);
17        fast = squareSumOfDigits(squareSumOfDigits(fast));
18    } while (slow != fast);
19    return slow == 1;
20}
21};