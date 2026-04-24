// Last updated: 4/24/2026, 10:04:38 PM
class Solution {
public:
    int minimumLength(string s) {
        map<char, int> frequency;
    // Iterate through the string and update frequencies
        for (char c : s) {
            frequency[c]++;
        }
        for(auto& it:frequency){
            while(it.second>=3){
                it.second-=2;
            }
        }
        int minLength=0;
        for(auto it:frequency){
                minLength+=it.second;
        }
        return minLength;
    }
};