// Last updated: 4/24/2026, 10:04:19 PM
class Solution {
public:
    int possibleStringCount(string word) {
            int totalCount = 1;
    int i = 0;
    while (word[i] != '\0') {
        int j = i;
        while (word[j] != '\0' && word[j] == word[i]) {
            j++;
        }
        int groupLength = j - i;
        if (groupLength > 1) {
            totalCount += groupLength-1;
        }   
        i = j;
    }
    return totalCount;
    }
};