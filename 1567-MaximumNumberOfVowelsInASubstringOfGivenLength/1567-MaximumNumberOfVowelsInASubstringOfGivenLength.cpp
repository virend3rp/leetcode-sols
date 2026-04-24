// Last updated: 4/24/2026, 10:09:00 PM
class Solution {
public:
    int isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for (int i = 0; i < k; i++)
            count += isVowel(s[i]);

        int maxCount = count;

        for (int i = k; i < s.size(); i++) {
            count += isVowel(s[i]);     
            count -= isVowel(s[i - k]); 
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};