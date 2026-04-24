// Last updated: 4/25/2026, 1:25:03 AM
1class Solution {
2public:
3string convertDateToBinary(string date) {
4    int year  = stoi(date.substr(0, 4));
5    int month = stoi(date.substr(5, 2));
6    int day   = stoi(date.substr(8, 2));
7
8    auto toBin = [](int n) {
9        string res = "";
10        while (n > 0) {
11            res = char('0' + n % 2) + res;
12            n /= 2;
13        }
14        return res;
15    };
16
17    return toBin(year) + "-" + toBin(month) + "-" + toBin(day);
18}
19};