// Last updated: 4/24/2026, 10:09:48 PM
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        if(words.empty()) return res;
        
        res.push_back(words[0]);
        
        for (int i = 1; i < words.size(); i++) {
            string prev = res.back();
            string curr = words[i];
            
            // Sort both words to check if they are anagrams.
            string sortedPrev = prev;
            string sortedCurr = curr;
            sort(sortedPrev.begin(), sortedPrev.end());
            sort(sortedCurr.begin(), sortedCurr.end());
            
            // If they are not anagrams, add the current word to res.
            if (sortedPrev != sortedCurr)
                res.push_back(curr);
        }
        
        return res;
    }
};