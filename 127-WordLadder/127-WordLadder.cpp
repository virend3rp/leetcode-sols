// Last updated: 4/24/2026, 10:15:32 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); 
        if (wordSet.find(endWord) == wordSet.end()) return 0; 
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); 
        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();
            if (word == endWord) return length; 
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue; 
                    word[i] = c;
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, length + 1});
                        wordSet.erase(word); 
                    }
                }
                word[i] = originalChar; 
            }
        }
        return 0;
    }
};