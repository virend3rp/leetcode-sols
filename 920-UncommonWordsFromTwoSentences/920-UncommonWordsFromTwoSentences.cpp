// Last updated: 4/24/2026, 10:11:15 PM
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        
        // Combine both sentences into one stream
        stringstream ss(s1 + " " + s2);
        string word;
        
        // Count occurrences of each word
        while (ss >> word) {
            wordCount[word]++;
        }
        
        vector<string> result;
        for (auto& pair : wordCount) {
            if (pair.second == 1) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};