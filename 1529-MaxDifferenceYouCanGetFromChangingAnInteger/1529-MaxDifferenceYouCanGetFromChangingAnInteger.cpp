// Last updated: 4/24/2026, 10:09:07 PM
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Maximize: replace first non-9 digit with 9
        string high = s;
        for (char& c : high) {
            if (c != '9') {
                char target = c;
                for (char& ch : high) {
                    if (ch == target) ch = '9';
                }
                break;
            }
        }

        string low = s;
        if (low[0] != '1') {
            char target = low[0];
            for (char& ch : low) {
                if (ch == target) ch = '1';
            }
        } else {
            for (int i = 1; i < low.size(); ++i) {
                if (low[i] != '0' && low[i] != '1') {
                    char target = low[i];
                    for (int j = 1; j < low.size(); ++j) {
                        if (low[j] == target) low[j] = '0';
                    }
                    break;
                }
            }
        }

        int a = stoi(high), b = stoi(low);
        return a - b;
    }

};